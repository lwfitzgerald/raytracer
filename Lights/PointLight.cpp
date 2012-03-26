#include "PointLight.h"
#include "../Utils/ShadeInfo.h"

PointLight::PointLight()
: Light() {
    castsShadows = true;
}

Vector3 PointLight::getDirection(const ShadeInfo& shadeInfo) const {
    return (location - shadeInfo.hitPoint).hat();
}

Colour PointLight::getRadiance(const ShadeInfo& shadeInfo) const {
    return colour * intensity;
}

void PointLight::setLocation(const Point3& location) {
    this->location = location;
}
