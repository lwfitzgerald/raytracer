/*
 * Point3.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#include "Point3.h"

__inline Point3 Point3::operator+(const Vector3& other) const {
    return Point3(
        this->x + other.x,
        this->y + other.y,
        this->z + other.z
    );
}

__inline Point3 Point3::operator-(const Vector3& rhs) const {
    return Point3(
        this->x - rhs.x,
        this->y - rhs.y,
        this->z - rhs.z
    );
}

__inline Vector3 Point3::operator-(const Point3& rhs) const {
    return Vector3(
        this->x - rhs.x,
        this->y - rhs.y,
        this->z - rhs.z
    );
}

__inline Point3& Point3::operator=(const Point3& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;

    return *this;
}

__inline Point3& Point3::operator+=(const Vector3& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;

    return *this;
}

__inline Point3& Point3::operator-=(const Vector3& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;

    return *this;
}
