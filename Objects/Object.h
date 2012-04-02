#ifndef OBJECT_H_
#define OBJECT_H_

#include "../Prereqs.h"
#include "../Utils/BoundingBox.h"

namespace Raytracer {
    class Object {
    public:
        Material* material;

        virtual ~Object() {};

        virtual bool hit(const Ray& ray, double& tmin) const = 0;
        virtual void getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const = 0;

        virtual bool isBoundable() const = 0;
        virtual BoundingBox getBoundingBox() const = 0;

        virtual void setMaterial(Material* material);

    protected:
        Object() {};

        void fetchMaterial(std::istringstream& iss, World& world);
    };
}

#endif /* OBJECT_H_ */
