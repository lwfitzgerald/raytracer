/*
 * Point.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef POINT_H_
#define POINT_H_

#include "Vector3.h"

class Point3 {
public:
    double x;
    double y;
    double z;

    __inline Point3() {}

    __inline Point3(const double x, const double y, const double z)
    : x(x), y(y), z(z) {}

    __inline Point3(const Point3& old)
    : x(old.x), y(old.y), z(old.z) {}

    __inline ~Point3() {}

    __inline Point3 operator+(const Vector3& other) const;
    __inline Point3 operator-(const Vector3& rhs) const;

    __inline Vector3 operator-(const Point3& rhs) const;

    __inline Point3& operator=(const Point3& rhs);

    __inline Point3& operator+=(const Vector3& rhs);
    __inline Point3& operator-=(const Vector3& rhs);
};

#endif /* POINT_H_ */
