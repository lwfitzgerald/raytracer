#ifndef SPHERE_H_
#define SPHERE_H_

#include "Object.h"
#include "../Utils/Point3.h"

namespace Raytracer {
    class Sphere: public Object {
    public:
        /**
         * Construct a sphere with the given parameters
         */
        Sphere(const Point3& center, const double& radius)
        : center(center), radius(radius) {}

        /**
         * Copy constructor
         */
        Sphere(const Sphere& old)
        : center(old.center), radius(old.radius) {}

        /**
         * Construct a Sphere from the
         */
        Sphere(std::istringstream& iss, World& world);

        virtual ~Sphere() {}

        Sphere& operator=(Sphere& rhs);

        virtual bool hit(const Ray& ray, double& tmin) const;
        virtual void getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const;

        virtual bool isBoundable() const;

        virtual BoundingBox getBoundingBox() const;

    private:
        Point3 center;
        double radius;
    };
}

#endif /* SPHERE_H_ */
