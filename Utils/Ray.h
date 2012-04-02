#ifndef RAY_H_
#define RAY_H_

#include "../Prereqs.h"

#include "Point3.h"
#include "Vector3.h"
#include "Normal.h"
#include "../Objects/Object.h"

namespace Raytracer {
    class Ray {
    public:
        Point3 origin;
        Vector3 direction;

        Ray()
        : origin(0.0, 0.0, 0.0), direction(0.0, 0.0, -1.0) {}

        Ray(const Point3& origin, const Vector3& direction)
        : origin(origin), direction(direction) {}

        Ray(const Ray& old)
        : origin(old.origin), direction(old.direction) {}

        ~Ray() {}

        Ray& operator=(const Ray& rhs);

        Ray getReflectedRay(const ShadeInfo& shadeInfo) const;

        /**
         * Get the information required to reflect
         * and refract rays when hitting a transparent
         * material.
         *
         * Returns true if a refracted ray exists
         */
        bool getTransparentDetails(const ShadeInfo& shadeInfo, double ior,
            double& reflectionCoeff, double& transmitCoeff,
            Ray& refractedRay) const;

        static Ray getShadowRay(const ShadeInfo& shadeInfo, const Light& light);
    };
}

#endif /* RAY_H_ */
