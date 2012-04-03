#include "AmbientLight.h"

namespace Raytracer {
    AmbientLight::AmbientLight()
    : Light() {
        mCastsShadows = false;
    }

    AmbientLight::AmbientLight(std::istringstream& iss)
    : Light(iss) {
        mCastsShadows = false;
    }

    Vector3 AmbientLight::getDirection(const ShadeInfo& shadeInfo) const {
        // Should not be called
        return Vector3(0, 0, 0);
    }

    Vector3 AmbientLight::getDirectionToHitPoint(const ShadeInfo& shadeInfo) const {
        // Should not be called
        return Vector3(0, 0, 0);
    }

    Colour AmbientLight::getRadiance(const ShadeInfo& shadeInfo) const {
        return colour * intensity;
    }

    bool AmbientLight::inShadow(const ShadeInfo& shadeInfo, const World& world) const {
        // Ambient light doesn't shadow
        return false;
    }
}
