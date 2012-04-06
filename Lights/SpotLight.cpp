#include "SpotLight.h"
#include "../Utils/ShadeInfo.h"
#include "../World.h"

namespace Raytracer {
    SpotLight::SpotLight(std::istringstream& iss)
    : PointLight(iss) {
        double directionX, directionY, directionZ;

        iss >> directionX;
        iss >> directionY;
        iss >> directionZ;

        iss >> rateOfFallOff;

        direction = Vector3(directionX, directionY, directionZ).hat();
    }

    Vector3 SpotLight::getDirection(const ShadeInfo& shadeInfo) const {
        return direction;
    }

    Vector3 SpotLight::getDirectionToHitPoint(const ShadeInfo& shadeInfo) const {
        return (shadeInfo.hitPoint - position).hat();
    }

    Colour SpotLight::getRadiance(const ShadeInfo& shadeInfo) const {
        return colour * intensity
            * pow(direction * getDirectionToHitPoint(shadeInfo),
                    rateOfFallOff);
    }

    void SpotLight::setDirection(const Vector3& direction) {
        this->direction = direction.hat();
    }

    void SpotLight::setRateOfFallOff(const double& rateOfFallOff) {
        this->rateOfFallOff = rateOfFallOff;
    }

    bool SpotLight::inShadow(const ShadeInfo& shadeInfo, const World& world) const {
        Ray shadowRay = Ray::getShadowRay(shadeInfo, *this);

        // Set tmin so as to prevent intersecting with objects past the light
        double tmin = (position - shadowRay.origin) * shadowRay.direction;

        return world.shadowHitObjects(shadowRay, tmin);
    }
}
