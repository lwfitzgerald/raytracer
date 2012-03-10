/*
 * Point3.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#include "Point3.h"

Point3 Point3::operator+(const Vector3& other) const {
    return Point3(
        this->x + other.x,
        this->y + other.y,
        this->z + other.z
    );
}

Point3 Point3::operator-(const Vector3& rhs) const {
    return Point3(
        this->x - rhs.x,
        this->y - rhs.y,
        this->z - rhs.z
    );
}

Vector3 Point3::operator-(const Point3& rhs) const {
    return Vector3(
        this->x - rhs.x,
        this->y - rhs.y,
        this->z - rhs.z
    );
}

Point3& Point3::operator=(const Point3& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;

    return *this;
}

Point3 Point3::operator*(const double& rhs) const {
    return Point3(
        rhs * this->x,
        rhs * this->y,
        rhs * this->z
    );
}

Point3& Point3::operator+=(const Vector3& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;

    return *this;
}

Point3& Point3::operator-=(const Vector3& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;

    return *this;
}

bool Point3::operator==(const Point3& rhs) {
    return this->x == rhs.x &&
           this->y == rhs.y &&
           this->z == rhs.z;
}
