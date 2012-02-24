/*
 * Plane.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#include "Plane.h"
#include "Ray.h"

Plane& Plane::operator=(const Plane& rhs) {
    this->position = rhs.position;
    this->normal = rhs.normal;

    return *this;
}

bool Plane::hit(const Ray& ray, double& tmin, ShadeInfo& shadeInfo) const {
    double t = ((this->position - ray.origin) * this->normal) / (ray.direction * this->normal);

    if (t > this->epsilon) {
        tmin = t;

        return true;
    }

    return false;
}
