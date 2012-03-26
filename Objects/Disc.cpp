/*
 * Disc.cpp
 *
 *  Created on: 26 Mar 2012
 *      Author: darkip
 */

#include "Disc.h"
#include "../Utils/Ray.h"
#include "../Utils/ShadeInfo.h"

Disc& Disc::operator=(const Disc& rhs) {
    Plane::operator=(rhs);

    this->radius = rhs.radius;

    return *this;
}

bool Disc::hit(const Ray& ray, double& tmin) const {
    double planarT = tmin;

    if (Plane::hit(ray, planarT)) {
        Point3 pointOfIntersection = ray.origin + planarT * ray.direction;

        // Check if point of intersection is inside radius
        if ((pointOfIntersection - this->position) * (pointOfIntersection - this->position) <= sqr(this->radius)) {
            tmin = planarT;
            return true;
        }
    }

    return false;
}
