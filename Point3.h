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

    __inline Point3(const double x, const double y, const double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    __inline Point3(const Point3& old) {
        this->x = old.x;
        this->y = old.y;
        this->z = old.z;
    }

    __inline ~Point3() {}

    __inline Point3 operator-() {
        return Point3(
            -this->x,
            -this->y,
            -this->z
        );
    }

    __inline Point3 operator+(const Vector3& other) {
        return Point3(
            this->x + other.x,
            this->y + other.y,
            this->z + other.z
        );
    }

    __inline Point3 operator-(const Vector3& rhs) {
        return Point3(
            this->x - rhs.x,
            this->y - rhs.y,
            this->z - rhs.z
        );
    }

    __inline Vector3 operator-(const Point3& rhs) {
        return Vector3(
            this->x - rhs.x,
            this->y - rhs.y,
            this->z - rhs.z
        );
    }

    __inline Point3& operator=(const Point3& rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;

        return *this;
    }

    __inline Point3& operator+=(const Vector3& rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;

        return *this;
    }

    __inline Point3& operator-=(const Vector3& rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;

        return *this;
    }
};

#endif /* POINT_H_ */
