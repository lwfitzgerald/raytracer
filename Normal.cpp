/*
 * Normal.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#include "Normal.h"
#include "Vector3.h"

Normal Normal::operator-() const {
    return Normal(
        -this->x,
        -this->y,
        -this->z
    );
}

Normal Normal::operator+(const Normal& rhs) const {
    return Normal(
        this->x + rhs.x,
        this->y + rhs.y,
        this->z + rhs.z
    );
}

Vector3 Normal::operator+(const Vector3& rhs) const {
    return Vector3(
        this->x + rhs.x,
        this->y + rhs.y,
        this->z + rhs.z
    );
}

Normal Normal::operator*(const double& rhs) const {
    return Normal(
        rhs * this->x,
        rhs * this->y,
        rhs * this->z
    );
}

double Normal::operator*(const Vector3& rhs) const {
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

Normal& Normal::operator=(const Normal& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;

    return *this;
}

Normal& Normal::operator+=(const Normal& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;

    return *this;
}

Normal& Normal::operator-=(const Normal& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;

    return *this;
}
