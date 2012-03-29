#include "DirectionalLight.h"

DirectionalLight::DirectionalLight()
: Light() {
    castsShadows = true;
}

DirectionalLight::DirectionalLight(std::istringstream& iss)
: Light(iss) {
    castsShadows = true;

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
