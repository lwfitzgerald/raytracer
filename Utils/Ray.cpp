#include "Ray.h"
#include "ShadeInfo.h"
#include "../Lights/Light.h"

namespace Raytracer {
    Ray& Ray::operator=(const Ray& rhs) {
        origin = rhs.origin;
        direction = rhs.direction;

        return *this;
    }

    Ray Ray::getReflectedRay(const ShadeInfo& shadeInfo) const {
        Vector3 reflectedDirection = direction
            - 2.0 * (direction * shadeInfo.hitNormal) * shadeInfo.hitNormal;
        return Ray(shadeInfo.hitPoint + EPSILON * reflectedDirection, reflectedDirection);
    }

    Ray Ray::getShadowRay(const ShadeInfo& shadeInfo, const Light& light) {
        return Ray(
            shadeInfo.hitPoint + EPSILON * -light.getDirection(shadeInfo),
            -light.getDirection(shadeInfo)
        );
    }
}
