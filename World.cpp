#include "World.h"

#include "Utils/Ray.h"
#include "Utils/ShadeInfo.h"
#include "Utils/Point3.h"
#include "Objects/Plane.h"
#include "Objects/Sphere.h"
#include "Objects/Disc.h"
#include "Objects/Triangle.h"
#include "Cameras/RegularCamera.h"
#include "Lights/DirectionalLight.h"
#include "Lights/PointLight.h"
#include "Materials/Matte.h"
#include "Materials/Specular.h"
#include "Utils/BVHNode.h"

namespace Raytracer {
    World::~World() {
        // Delete the camera
        delete this->camera;

        // Delete the ambient light
        delete this->ambientLight;

        // Delete materials
        std::map<const std::string, Material*>::iterator materialItr;

        for (materialItr=materials.begin(); materialItr != materials.end(); materialItr++) {
            delete materialItr->second;
        }

        deleteBVHNode(bvh);

        // Delete all objects
        std::vector<Object*>::iterator objectItr;

        for (objectItr=objects.begin(); objectItr < objects.end(); objectItr++) {
            delete *objectItr;
        }
    }

    void World::renderScene() {
        std::cout << "Rendering scene..." << std::endl;
        double start = omp_get_wtime();

        int j;

#pragma omp parallel for private(j) schedule(dynamic)
        for (int i=0; i < viewPlane.verticalRes; i++) {
            for (j=0; j < viewPlane.horizontalRes; j++) {
                camera->renderPixel(j, i, *this);
            }
        }

        double end = omp_get_wtime();
        double time = (end - start) * 1000;

        std::cout << "Scene rendered in " << time << "ms" << std::endl;
        std::cout << "Writing output file..." << std::endl;
        start = omp_get_wtime();

        // Write output image
        viewPlane.writePPM(OUTPUT_FILENAME);

        end = omp_get_wtime();
        time = (end - start) * 1000;
        std::cout << "Output file written in " << time << "ms" << std::endl;
    }

    ShadeInfo World::hitObjects(const Ray& ray, const unsigned int depth) const {
        ShadeInfo shadeInfo;

        // Set tmin to infinity
        double tmin = std::numeric_limits<double>::infinity();

        // Before handling BVH, intersect with unboundable objects

        std::vector<Object*>::const_iterator itr;

        for (itr=unboundableObjects.begin(); itr != unboundableObjects.end(); itr++) {
            if ((*itr)->hit(ray, tmin)) {
                shadeInfo.hit = true;
                shadeInfo.ray = ray;
                shadeInfo.hitObject = *itr;
            }
        }

        // Intersect with the BVH objects
        hitBVHObjects(ray, bvh, shadeInfo, tmin);

        if (shadeInfo.hit) {
            // Some object was hit so get the shading information for it
            shadeInfo.hitObject->getShadeInfo(shadeInfo, ray, tmin);

            shadeInfo.colour = shadeInfo.hitObject->material->shade(shadeInfo, *this, depth);
        }

        return shadeInfo;
    }

    bool World::shadowHitObjects(const Ray& ray, double& tmin) const {
        ShadeInfo shadeInfo;

        // Before handling BVH, intersect with unboundable objects

        std::vector<Object*>::const_iterator itr;

        for (itr=unboundableObjects.begin(); itr != unboundableObjects.end(); itr++) {
            if ((*itr)->hit(ray, tmin)) {
                return true;
            }
        }

        // Intersect with the BVH objects
        return shadowHitBVHObjects(ray, bvh, tmin);
    }

    void World::hitBVHObjects(const Ray& ray, BVHNode* bvhNode,
        ShadeInfo& shadeInfo, double& tmin) const {
        if (!bvhNode->boundingBox.hit(ray)) {
            // No intersection with bounding box
            return;
        }

        if (bvhNode->objects != NULL) {
            // Leaf node so intersect with objects

            std::vector<Object*>::const_iterator itr;

            for (itr=bvhNode->objects->begin(); itr != bvhNode->objects->end(); itr++) {
                if ((*itr)->hit(ray, tmin)) {
                    shadeInfo.hit = true;
                    shadeInfo.ray = ray;
                    shadeInfo.hitObject = *itr;
                }
            }
            return;
        }

        // Do the recursive calls
        hitBVHObjects(ray, bvhNode->left, shadeInfo, tmin);
        hitBVHObjects(ray, bvhNode->right, shadeInfo, tmin);
    }

    bool World::shadowHitBVHObjects(const Ray& ray, BVHNode* bvhNode,
        const double& tmin) const {
        if (!bvhNode->boundingBox.hit(ray)) {
            // No intersection with bounding box
            return false;
        }

        if (bvhNode->objects != NULL) {
            // Leaf node so intersect with objects

            double t = tmin;
            std::vector<Object*>::const_iterator itr;

            for (itr=bvhNode->objects->begin(); itr != bvhNode->objects->end(); itr++) {
                if ((*itr)->hit(ray, t)) {
                    return true;
                }
            }
            return false;
        }

        // Do the recursive calls
        bool leftResult = shadowHitBVHObjects(ray, bvhNode->left, tmin);
        bool rightResult = shadowHitBVHObjects(ray, bvhNode->right, tmin);

        return leftResult || rightResult;
    }

    void World::addObject(Object* object) {
        this->objects.push_back(object);
    }

    void World::addLight(Light* light) {
        this->lights.push_back(light);
    }

    void World::addMaterial(Material* material) {
        this->materials[material->name] = material;
    }

    void World::buildBVH() {
        std::cout << "Building BVH..." << std::endl;
        double start = omp_get_wtime();

        bvh = new BVHNode;

        std::vector<Object*>* objects = new std::vector<Object*>(this->objects);

        // Remove all unboundable objects

        std::vector<Object*>::iterator itr;

        for (itr=objects->begin(); itr != objects->end();) {
            if (!(*itr)->isBoundable()) {
                // Push into unboundable list
                unboundableObjects.push_back(*itr);

                // Remove from BVH build objects list
                itr = objects->erase(itr);
            } else {
                itr++;
            }
        }

        // Order by X axis first
        buildBVH(bvh, objects, Z_AXIS);

        double end = omp_get_wtime();
        double time = (end - start) * 1000;
        std::cout << "BVH built in " << time << "ms" << std::endl;
    }

    bool World::buildBVH(BVHNode* currentNode, std::vector<Object*>* currentObjects, const Axis lastAxis) {
        // Store bounding box for the node
        currentNode->boundingBox = getBoundingBox(currentObjects);

        if (currentObjects->size() <= MAX_BVH_LEAF_OBJECTS) {
            // Sufficiently small number of nodes in bounding box, make this a leaf node
            currentNode->objects = currentObjects;
            return true;
        }

        // Create left and right nodes
        currentNode->left = new BVHNode;
        currentNode->right = new BVHNode;

        // Choose axis to order objects on
        Axis orderAxis;
        if (lastAxis == X_AXIS) {
            orderAxis = Y_AXIS;
        } else if (lastAxis == Y_AXIS) {
            orderAxis = Z_AXIS;
        } else {
            orderAxis = X_AXIS;
        }

        // Build left and right object lists

        const std::vector<Object*> orderObjects = orderByAxisDistance(currentObjects, orderAxis);

        std::vector<Object*>* leftObjects = new std::vector<Object*>(orderObjects.size() / 2);

        for (unsigned int i=0; i < orderObjects.size() / 2; i++) {
            (*leftObjects)[i] = orderObjects[i];
        }

        unsigned int rightStart = orderObjects.size() / 2;
        unsigned int rightSize = orderObjects.size() - rightStart;

        std::vector<Object*>* rightObjects = new std::vector<Object*>(rightSize);

        unsigned int j = 0;
        for (unsigned int i=rightStart; i < orderObjects.size(); i++) {
            (*rightObjects)[j] = orderObjects[i];
            j++;
        }

        // Do the recursive calls
        bool leftResult = buildBVH(currentNode->left, leftObjects, orderAxis);
        bool rightResult = buildBVH(currentNode->right, rightObjects, orderAxis);

        // If the recursive call did not create a leaf, delete the temporary vector
        if (!leftResult) {
            delete leftObjects;
        }

        if (!rightResult) {
            delete rightObjects;
        }

        return false;
    }

    void World::deleteBVHNode(BVHNode* bvhNode) {
        if (bvhNode->objects != NULL) {
            delete bvhNode->objects;
        }

        if (bvhNode->left != NULL) {
            deleteBVHNode(bvhNode->left);
        }

        if (bvhNode->right != NULL) {
            deleteBVHNode(bvhNode->right);
        }

        delete bvhNode;
    }

    BoundingBox World::getBoundingBox(std::vector<Object*>* objects) {
        if (objects->size() == 0) {
            return BoundingBox(Point3(0, 0, 0), Point3(0, 0, 0));
        }

        // Initialise the box to the bounding box of the first object
        BoundingBox boundingBox = (*objects->begin())->getBoundingBox();

        std::vector<Object*>::const_iterator itr;

        // Start from the second object

        for (itr=++(objects->begin()); itr != objects->end(); itr++) {
            BoundingBox objectBox = (*itr)->getBoundingBox();
            boundingBox.corner1 = Point3(
                std::min(objectBox.corner1.x, boundingBox.corner1.x),
                std::min(objectBox.corner1.y, boundingBox.corner1.y),
                std::min(objectBox.corner1.z, boundingBox.corner1.z)
            );
            boundingBox.corner2 = Point3(
                std::max(objectBox.corner2.x, boundingBox.corner2.x),
                std::max(objectBox.corner2.y, boundingBox.corner2.y),
                std::max(objectBox.corner2.z, boundingBox.corner2.z)
            );
        }

        return boundingBox;
    }

    std::vector<Object*> World::orderByAxisDistance(const std::vector<Object*>* currentObjects, const Axis axis) {
        std::vector<Object*> orderedObjects = std::vector<Object*>(*currentObjects);

        if (axis == X_AXIS) {
            std::sort(orderedObjects.begin(), orderedObjects.end(), World::compareX);
        } else if (axis == Y_AXIS) {
            std::sort(orderedObjects.begin(), orderedObjects.end(), World::compareY);
        } else {
            std::sort(orderedObjects.begin(), orderedObjects.end(), World::compareZ);
        }

        return orderedObjects;
    }

    bool World::compareX(const Object* obj1, const Object* obj2) {
        BoundingBox obj1Box = obj1->getBoundingBox();
        BoundingBox obj2Box = obj2->getBoundingBox();

        return obj1Box.corner1.x < obj2Box.corner1.x;
    }

    bool World::compareY(const Object* obj1, const Object* obj2) {
        BoundingBox obj1Box = obj1->getBoundingBox();
        BoundingBox obj2Box = obj2->getBoundingBox();

        return obj1Box.corner1.y < obj2Box.corner1.y;
    }

    bool World::compareZ(const Object* obj1, const Object* obj2) {
        BoundingBox obj1Box = obj1->getBoundingBox();
        BoundingBox obj2Box = obj2->getBoundingBox();

        return obj1Box.corner2.z < obj2Box.corner2.z;
    }

    void World::setCamera(Camera* camera) {
        this->camera = camera;
    }

    void World::setAmbientLight(AmbientLight* ambientLight) {
        this->ambientLight = ambientLight;
    }

    void World::setViewPlaneResolution(const unsigned int hres, const unsigned int vres) {
        this->viewPlane.setResolution(hres, vres);
    }

    void World::setViewPlanePixelSize(float pixelSize) {
        this->viewPlane.setPixelSize(pixelSize);
    }
}
