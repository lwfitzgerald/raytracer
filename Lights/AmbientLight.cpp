#include "AmbientLight.h"

AmbientLight::AmbientLight()
: Light() {
    castsShadows = false;
}

AmbientLight::AmbientLight(std::istringstream& iss)
: Light(iss) {
    castsShadows = false;
}

Vector3 AmbientLight::getDirection(const ShadeInfo& shadeInfo) const {
    return Vector3(0.0, 0.0, 0.0);
}

Colour AmbientLight::getRadiance(const ShadeInfo& shadeInfo) const {
    return colour * intensity;
}
