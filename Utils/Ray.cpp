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

    bool Ray::getTransparentDetails(const ShadeInfo& shadeInfo,
        double& reflectionCoeff, double& transmitCoeff,
        Ray& refractedRay) const {

        double ior = shadeInfo.hitIoR;
        Normal normal = shadeInfo.hitNormal;

        double cos_i = normal * -direction;

        if (cos_i < 0) {
            // Flip when intersecting from inside
            ior = 1 / ior;
            normal = -normal;
            cos_i = -cos_i;
        }

        double cos_t_sqr = 1 - (1 / sqr(ior)) * (1 - sqr(cos_i));

        if (cos_t_sqr < 0) {
            // Total internal reflection (refracted ray does not exist)
            reflectionCoeff = 1;
            return false;
        }

        double cos_t = sqrt(cos_t_sqr);

        // Using fresnel equations calculate coeffs
        double rPar = (ior * cos_i - cos_t) / (ior * cos_i + cos_t);
        double rPer = (cos_i - ior * cos_t) / (cos_i + ior * cos_t);

        reflectionCoeff = 0.5 * (sqr(rPar) + sqr(rPer));
        transmitCoeff = 1 - reflectionCoeff;

        // Calculate transmitted (refracted) ray

        Vector3 refractedDirection = (1 / ior) *
            direction - (cos_t - (1 / ior) * cos_i)
            * normal;

        refractedRay = Ray(shadeInfo.hitPoint + EPSILON * refractedDirection,
            refractedDirection);

        return true;
    }

    Ray Ray::getShadowRay(const ShadeInfo& shadeInfo, const Light& light) {
        return Ray(
            shadeInfo.hitPoint + EPSILON * -light.getDirection(shadeInfo),
            -light.getDirection(shadeInfo)
        );
    }
}
