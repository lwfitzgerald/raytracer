/*
 * Sphere.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#include "Sphere.h"
#include "Ray.h"
#include "Vector3.h"
#include "ShadeInfo.h"

Sphere& Sphere::operator=(Sphere& rhs) {
    this->center = rhs.center;
    this->radius = rhs.radius;

    return *this;
}

bool Sphere::hit(const Ray& ray, double& tmin, ShadeInfo& shadeInfo) const {
    Vector3 oMinusC = ray.origin - this->center;
    const double a = ray.direction * ray.direction;
    const double b = 2.0 * ray.direction * oMinusC;
    const double c = oMinusC * oMinusC - sqr(this->radius);
    const double disc = sqr(b) - 4.0 * a * c;

    if (disc < 0) {
        // No hits
        return false;
    }

    const double discroot = sqrt(disc);
    const double denom = 2.0 * a;

    // Handle the - root
    double t = (-b - discroot) / denom;

    if (t > this->epsilon) {
        tmin = t;

        // Normal calculated by vector from C to P and then normalised using the radius
        shadeInfo.hitNormal = (oMinusC + t * ray.direction) / this->radius;
        shadeInfo.hitPoint = ray.origin + t * ray.direction;
        return true;
    }

    // Handle the + root
    t = (-b + discroot) / denom;

    if (t > this->epsilon) {
        tmin = t;

        shadeInfo.hitNormal = (oMinusC + t * ray.direction) / this->radius;
        shadeInfo.hitPoint = ray.origin + t * ray.direction;
        return true;
    }

    return false;
}