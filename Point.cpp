/*
 * Point.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#include "Point.h"

Point::Point() {}

Point::Point(const double x, const double y, const double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(const Point& old) {
    this->x = old.x;
    this->y = old.y;
    this->z = old.z;
}

Point::~Point() {}

Point Point::operator-() {
    return Point(
        -this->x,
        -this->y,
        -this->z
    );
}

Point Point::operator+(const Vector3& rhs) {
    return Point(
        this->x + rhs.x,
        this->y + rhs.y,
        this->z + rhs.z
    );
}

Point Point::operator-(const Vector3& rhs) {
    return Point(
        this->x - rhs.x,
        this->y - rhs.y,
        this->z - rhs.z
    );
}

Vector3 Point::operator-(const Point& rhs) {
    return Vector3(
        this->x - rhs.x,
        this->y - rhs.y,
        this->z - rhs.z
    );
}

Point& Point::operator=(const Point& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;

    return *this;
}
