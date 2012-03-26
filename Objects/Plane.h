/*
 * Plane.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef PLANE_H_
#define PLANE_H_

#include "Object.h"
#include "../Utils/Point3.h"
#include "../Utils/Normal.h"

class Plane: public Object {
public:
    Plane() {}

    Plane(const Point3 &position, const Normal& normal)
    : position(position), normal(normal) {}

    Plane(const Plane& old)
    : position(old.position), normal(old.normal) {}

    virtual ~Plane() {}

    Plane& operator=(const Plane& rhs);

    virtual bool hit(const Ray& ray, double& tmin) const;
    virtual void getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const;

protected:
    Point3 position;
    Normal normal;
};

#endif /* PLANE_H_ */
