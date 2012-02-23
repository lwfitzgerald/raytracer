/*
 * Ray.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef RAY_H_
#define RAY_H_

#include "Point3.h"
#include "Vector3.h"

class Ray {
public:
    Point3 origin;
    Vector3 direction;

    Ray() {}

    Ray(const Point3& origin, const Vector3& direction)
    : origin(origin), direction(direction) {}

    Ray(const Ray& old)
    : origin(old.origin), direction(old.direction) {}

    ~Ray();

    Ray& operator=(const Ray& rhs);
};

#endif /* RAY_H_ */
