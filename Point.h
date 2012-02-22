/*
 * Point.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef POINT_H_
#define POINT_H_

#include "Vector3.h"

class Point {
public:
    double x;
    double y;
    double z;

    __inline Point() {}

    __inline Point(const double x, const double y, const double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    __inline Point(const Point& old) {
        this->x = old.x;
        this->y = old.y;
        this->z = old.z;
    }

    __inline ~Point() {}

    __inline Point operator-() {
        return Point(
            -this->x,
            -this->y,
            -this->z
        );
    }

    __inline Point operator+(const Vector3& other) {
        return Point(
            this->x + other.x,
            this->y + other.y,
            this->z + other.z
        );
    }

    __inline Point operator-(const Vector3& rhs) {
        return Point(
            this->x - rhs.x,
            this->y - rhs.y,
            this->z - rhs.z
        );
    }

    __inline Vector3 operator-(const Point& rhs) {
        return Vector3(
            this->x - rhs.x,
            this->y - rhs.y,
            this->z - rhs.z
        );
    }

    __inline Point& operator=(const Point& rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;

        return *this;
    }

    __inline Point& operator+=(const Vector3& rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;

        return *this;
    }

    __inline Point& operator-=(const Vector3& rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;

        return *this;
    }
};

#endif /* POINT_H_ */
