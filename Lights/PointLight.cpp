#include "PointLight.h"
#include "../Utils/ShadeInfo.h"

namespace Raytracer {
    PointLight::PointLight()
    : Light() {
        castsShadows = true;
    }

    PointLight::PointLight(std::istringstream& iss)
    : Light(iss) {
        castsShadows = true;

        // Extract position

        double x, y, z;

        iss >> x;
        iss >> y;
        iss >> z;

        // Create and set position
        position = Point3(x, y, z);
    }

    Vector3 PointLight::getDirection(const ShadeInfo& shadeInfo) const {
        return (position - shadeInfo.hitPoint).hat();
    }

    Colour PointLight::getRadiance(const ShadeInfo& shadeInfo) const {
        return colour * intensity;
    }

    void PointLight::setPosition(const Point3& position) {
        this->position = position;
    }
}
