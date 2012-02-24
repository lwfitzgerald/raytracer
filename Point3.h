/*
 * Point.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef POINT_H_
#define POINT_H_

#include "Prereqs.h"

#include "Vector3.h"

class Point3 {
public:
    double x;
    double y;
    double z;

    Point3() {}

    Point3(const double x, const double y, const double z)
    : x(x), y(y), z(z) {}

    Point3(const Point3& old)
    : x(old.x), y(old.y), z(old.z) {}

    ~Point3() {}

    Point3 operator+(const Vector3& other) const;
    Point3 operator-(const Vector3& rhs) const;

    Vector3 operator-(const Point3& rhs) const;

    Point3& operator=(const Point3& rhs);

    friend Point3 operator*(const double& lhs, const Point3& rhs) {
        return rhs * lhs;
    }
    Point3 operator*(const double& rhs) const;

    Point3& operator+=(const Vector3& rhs);
    Point3& operator-=(const Vector3& rhs);
};

#endif /* POINT_H_ */
