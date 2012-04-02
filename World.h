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

        void renderScene();

        void addObject(Object* object);
        void addLight(Light* light);
        void addMaterial(Material* material);

        void setViewPlaneResolution(const unsigned int hres, const unsigned int vres);
        void setViewPlanePixelSize(const float pixelSize);
        void setCamera(Camera* camera);
        void setAmbientLight(AmbientLight* ambientLight);

        void buildBVH();

        ShadeInfo hitObjects(const Ray& ray) const {
            return hitObjects(ray, 1);
        }

        ShadeInfo hitObjects(const Ray& ray, const unsigned int depth) const;
        bool shadowHitObjects(const Ray& ray, double& tmin) const;

        // Static methods used for sorting vectors of objects by an axis

        static bool compareX(const Object* obj1, const Object* obj2);

        static bool compareY(const Object* obj1, const Object* obj2);

        static bool compareZ(const Object* obj1, const Object* obj2);
    private:
        Camera* camera;

        bool buildBVH(BVHNode* currentNode, std::vector<Object*>* currentObjects, Axis lastAxis);
        static void deleteBVHNode(BVHNode* bvhNode);

        void hitBVHObjects(const Ray& ray, BVHNode* bvhNode, ShadeInfo& shadeInfo,
                    double& tmin, Object*& tminHitObject) const;
        bool shadowHitBVHObjects(const Ray& ray, BVHNode* bvhNode, double& tmin,
                    Object*& tminHitObject) const;

        BoundingBox getBoundingBox(std::vector<Object*>* objects);
        std::vector<Object*> orderByAxisDistance(std::vector<Object*>* currentObjects, Axis axis);
    };
}

#endif /* WORLD_H_ */
