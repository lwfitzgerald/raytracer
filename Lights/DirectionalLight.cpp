#include "DirectionalLight.h"
#include "../Utils/Ray.h"
#include "../World.h"

namespace Raytracer {
    DirectionalLight::DirectionalLight()
    : Light() {
        mCastsShadows = true;
    }

    DirectionalLight::DirectionalLight(std::istringstream& iss)
    : Light(iss) {
        mCastsShadows = true;

        // Extract direction

        double x, y, z;

        iss >> x;
        iss >> y;
        iss >> z;

        // Create and set direction
        direction = Vector3(x, y, z);
    }

    Vector3 DirectionalLight::getDirection(const ShadeInfo& shadeInfo) const {
        return direction;
    }

    Colour DirectionalLight::getRadiance(const ShadeInfo& shadeInfo) const {
        return colour * intensity;
    }

    void DirectionalLight::setDirection(const Vector3& direction) {
        this->direction = direction.hat();
    }

    bool DirectionalLight::inShadow(const ShadeInfo& shadeInfo, const World& world) const {
        Ray shadowRay = Ray::getShadowRay(shadeInfo, *this);

        double tmin = std::numeric_limits<double>::infinity();

        return world.shadowHitObjects(shadowRay, tmin);
    }
}
