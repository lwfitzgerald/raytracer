/*
 * Plane.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef PLANE_H_
#define PLANE_H_

#include "Prereqs.h"

#include "Object.h"
#include "Point3.h"
#include "Normal.h"

class Plane: public Object {
public:
    Plane() {}

    Plane(const Point3 &position, const Normal& normal)
    : position(position), normal(normal) {}

    Plane(const Plane& old)
    : position(old.position), normal(old.normal) {}

    virtual ~Plane();

    Plane& operator=(const Plane& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeInfo& shadeInfo) const;

private:
    Point3 position;
    Normal normal;
};

#endif /* PLANE_H_ */
