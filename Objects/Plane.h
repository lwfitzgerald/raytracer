#ifndef PLANE_H_
#define PLANE_H_

#include "Object.h"
#include "../Utils/Point3.h"
#include "../Utils/Normal.h"

namespace Raytracer {
    class Plane: public Object {
    public:
        /**
         * Construct a Plane using the given parameters
         */
        Plane(const Point3 &position, const Normal& normal)
        : position(position), normal(normal) {}

        /**
         * Copy constructor
         */
        Plane(const Plane& old)
        : position(old.position), normal(old.normal) {}

        /**
         * Construct a Plane from an istringstream
         */
        Plane(std::istringstream& iss, World& world);

        virtual ~Plane() {}

        Plane& operator=(const Plane& rhs);

        virtual bool hit(const Ray& ray, double& tmin) const;
        virtual void getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const;

        virtual bool isBoundable() const;

        virtual BoundingBox getBoundingBox() const;

    protected:
        Point3 position;
        Normal normal;

        Plane() {}

        /**
         * Performs all of the operations to construct
         * from an input line minus setting the material.
         * This allows child classes to have a variable
         * number of parameters.
         */
        void constructMinusMaterial(std::istringstream& iss);
    };
}

#endif /* PLANE_H_ */
