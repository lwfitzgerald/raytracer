#ifndef WORLD_H_
#define WORLD_H_

#include "Prereqs.h"

#include "Utils/Colour.h"
#include "Utils/ShadeInfo.h"
#include "ViewPlane.h"
#include "Lights/AmbientLight.h"

namespace Raytracer {
    class World {
    public:
        Colour backgroundColour;
        ViewPlane viewPlane;

        // Ambient light in the world
        AmbientLight* ambientLight;

        // Materials used in the world
        std::map<const std::string, Material*> materials;

        // Vector of objects in the world
        std::vector<Object*> objects;

        // Vector of lights in the world
        std::vector<Light*> lights;

        BVHNode* bvh;

        std::vector<Object*> unboundableObjects;

        World()
        :
            ambientLight(NULL),
            camera(NULL) {}

        ~World();

        /**
         * Render the scene
         */
        void renderScene();

        /**
         * Add an object to the world
         */
        void addObject(Object* object);

        /**
         * Add a light to the world
         */
        void addLight(Light* light);

        /**
         * Add a material to the world
         */
        void addMaterial(Material* material);

        /**
         * Set the view plane resolution
         */
        void setViewPlaneResolution(const unsigned int hres, const unsigned int vres);

        /**
         * Set the view plane pixel size
         */
        void setViewPlanePixelSize(const float pixelSize);

        /**
         * Set the camera to use to render
         */
        void setCamera(Camera* camera);

        /**
         * Set the ambient light
         */
        void setAmbientLight(AmbientLight* ambientLight);

        /**
         * Build the bounding volume hierarchy
         */
        void buildBVH();

        /**
         * Intersect the given ray with all objects in the world
         */
        ShadeInfo hitObjects(const Ray& ray) const {
            // Call to the recursive method
            return hitObjects(ray, 1);
        }

        /**
         * Recursive method to intersect the given ray with
         * all the objects in the world stopping at MAX_TRACE_DEPTH
         */
        ShadeInfo hitObjects(const Ray& ray, const unsigned int depth) const;

        /**
         * Intersect the given ray with all objects in scene returning
         * as soon as there is an intersection (before tmin)
         */
        bool shadowHitObjects(const Ray& ray, double& tmin) const;

        // Static methods used for sorting vectors of objects by an axis
        static bool compareX(const Object* obj1, const Object* obj2);

        static bool compareY(const Object* obj1, const Object* obj2);

        static bool compareZ(const Object* obj1, const Object* obj2);
    private:
        Camera* camera;

        /**
         * Recursive method for creating the BVH
         * starting from the given node with the given
         * objects
         */
        bool buildBVH(BVHNode* currentNode, std::vector<Object*>* currentObjects, const Axis lastAxis);

        /**
         * Static method for freeing the memory
         * allocated for a BVHNode (and it's children)
         */
        static void deleteBVHNode(BVHNode* bvhNode);

        /**
         * Recursive method for intersecting a ray with
         * the bounding volume hierarchy starting at
         * the given node
         */
        void hitBVHObjects(const Ray& ray, BVHNode* bvhNode, ShadeInfo& shadeInfo,
                    double& tmin, Object*& tminHitObject) const;

        /**
         * Recursive method for intersecting a ray with
         * the bounding volume hierarchy starting at
         * the given node returning as soon as there is
         * an intersection (before tmin)
         */
        bool shadowHitBVHObjects(const Ray& ray, BVHNode* bvhNode,
            const double& tmin) const;

        /**
         * Get the bounding box of the vector of objects
         */
        static BoundingBox getBoundingBox(std::vector<Object*>* objects);

        /**
         * Return the vector of objects provided sorted
         * from min to max values on the given axis
         */
        static std::vector<Object*> orderByAxisDistance(const std::vector<Object*>* currentObjects, const Axis axis);
    };
}

#endif /* WORLD_H_ */
