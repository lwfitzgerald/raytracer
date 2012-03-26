#include "Plane.h"
#include "../Utils/Ray.h"
#include "../Utils/ShadeInfo.h"

Plane& Plane::operator=(const Plane& rhs) {
    this->position = rhs.position;
    this->normal = rhs.normal;

    return *this;
}

bool Plane::hit(const Ray& ray, double& tmin) const {
    double t = (position - ray.origin) * normal / (ray.direction * normal);

    if (t > epsilon) {
        tmin = t;
        return true;
    }

    return false;
}

void Plane::getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const {
    shadeInfo.hitNormal = normal;
    shadeInfo.hitPoint = ray.origin + tmin * ray.direction;
}
