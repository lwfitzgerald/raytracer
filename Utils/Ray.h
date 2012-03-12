/*
 * Ray.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef RAY_H_
#define RAY_H_

#include "../Prereqs.h"

#include "Point3.h"
#include "Vector3.h"

class Ray {
public:
    Point3 origin;
    Vector3 direction;

    Ray()
    : origin(0.0, 0.0, 0.0), direction(0.0, 0.0, -1.0) {}

    Ray(const Point3& origin, const Vector3& direction)
    : origin(origin), direction(direction) {}

    Ray(const Ray& old)
    : origin(old.origin), direction(old.direction) {}

    ~Ray() {}

    Ray& operator=(const Ray& rhs) {
        this->origin = rhs.origin;
        this->direction = rhs.direction;

        return *this;
    }
};

#endif /* RAY_H_ */
