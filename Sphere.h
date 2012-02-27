/*
 * Sphere.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Prereqs.h"

#include "Object.h"
#include "Point3.h"

class Sphere: public Object {
public:
    Sphere() {}

    Sphere(const Point3& center, const double& radius)
    : center(center), radius(radius) {}

    Sphere(const Sphere& old)
    : center(old.center), radius(old.radius) {}

    virtual ~Sphere() {}

    Sphere& operator=(Sphere& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeInfo& shadeInfo) const;

private:
    Point3 center;
    double radius;
};

#endif /* SPHERE_H_ */