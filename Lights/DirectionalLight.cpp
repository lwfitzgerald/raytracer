#include "DirectionalLight.h"

DirectionalLight::DirectionalLight()
: Light() {
    // Directional lights cause shadows
    castsShadows = true;
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
