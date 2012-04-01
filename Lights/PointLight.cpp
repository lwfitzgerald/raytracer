#include "PointLight.h"
#include "../Utils/ShadeInfo.h"
#include "../World.h"

namespace Raytracer {
    PointLight::PointLight()
    : Light() {
        mCastsShadows = true;
    }

    PointLight::PointLight(std::istringstream& iss)
    : Light(iss) {
        mCastsShadows = true;

        // Extract position

        double x, y, z;

        iss >> x;
        iss >> y;
        iss >> z;

        // Create and set position
        position = Point3(x, y, z);
    }

    Vector3 PointLight::getDirection(const ShadeInfo& shadeInfo) const {
        return (shadeInfo.hitPoint - position).hat();
    }

    Colour PointLight::getRadiance(const ShadeInfo& shadeInfo) const {
        return colour * intensity;
    }

    void PointLight::setPosition(const Point3& position) {
        this->position = position;
    }

    bool PointLight::inShadow(const ShadeInfo& shadeInfo, const World& world) const {
        Ray shadowRay = Ray::getShadowRay(shadeInfo, *this);

        // Set tmin so as to prevent intersecting with objects past the light
        double tmin = (position - shadowRay.origin) * shadowRay.direction;

        return world.shadowHitObjects(shadowRay, tmin);
    }
}
