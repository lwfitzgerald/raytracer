#ifndef OBJECT_H_
#define OBJECT_H_

#include "../Prereqs.h"
#include "../Utils/BoundingBox.h"

namespace Raytracer {
    class Object {
    public:
        Material* material;

        virtual ~Object() {};

        /**
         * Attempt to intersect the given ray with the object
         * returning true if the ray intersects with a smaller
         * t parameter than the provided one. When returning
         * true, tmin will be set to the new t.
         */
        virtual bool hit(const Ray& ray, double& tmin) const = 0;

        /**
         * Fetch the shading information for the given intersection
         * data
         */
        virtual void getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const = 0;

        /**
         * Return whether the object can be surrounded by
         * a finite bounding box
         */
        virtual bool isBoundable() const = 0;

        /**
         * Get the bounding box for the object
         */
        virtual BoundingBox getBoundingBox() const = 0;

        /**
         * Set the material for this object
         */
        virtual void setMaterial(Material* material);

    protected:
        Object() {};

        /**
         * Extract the name of the material from the istringstream
         * and fetch the pointer to the material and store it in
         * the object
         */
        void fetchMaterial(std::istringstream& iss, const World& world);
    };
}

#endif /* OBJECT_H_ */
