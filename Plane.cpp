/*
 * Plane.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#include "Plane.h"
#include "Ray.h"
#include "ShadeInfo.h"

Plane& Plane::operator=(const Plane& rhs) {
    this->position = rhs.position;
    this->normal = rhs.normal;

    return *this;
}

bool Plane::hit(const Ray& ray, double& tmin) const {
    double t = (this->position - ray.origin) * this->normal / (ray.direction * this->normal);

    if (t > this->epsilon) {
        tmin = t;
        return true;
    }

    return false;
}

void Plane::getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const {
    shadeInfo.hitNormal = this->normal;
    shadeInfo.hitPoint = ray.origin + tmin * ray.direction;
}
