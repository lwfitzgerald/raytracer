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

        Ray& operator=(const Ray& rhs) {
            origin = rhs.origin;
            direction = rhs.direction;

            return *this;
        }

        Ray getReflectedRay(const Point3& hitPoint, const Normal& hitNormal) const {
            Vector3 reflectedDirection = direction - 2.0 * (direction * hitNormal) * hitNormal;
            return Ray(hitPoint + EPSILON * reflectedDirection, reflectedDirection);
        }
    };
}

#endif /* RAY_H_ */
