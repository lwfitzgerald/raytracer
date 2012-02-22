/*
 * Normal.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#include "Normal.h"
#include "Vector3.h"

__inline Normal Normal::operator-() const {
    return Normal(
        -this->x,
        -this->y,
        -this->z
    );
}

__inline Normal Normal::operator+(const Normal& rhs) const {
    return Normal(
        this->x + rhs.x,
        this->y + rhs.y,
        this->z + rhs.z
    );
}

__inline Vector3 Normal::operator+(const Vector3& rhs) const {
    return Vector3(
        this->x + rhs.x,
        this->y + rhs.y,
        this->z + rhs.z
    );
}

__inline Normal Normal::operator*(const double& rhs) const {
    return Normal(
        rhs * this->x,
        rhs * this->y,
        rhs * this->z
    );
}

__inline double Normal::operator*(const Vector3& rhs) const {
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

__inline Normal& Normal::operator=(const Normal& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;

    return *this;
}

__inline Normal& Normal::operator+=(const Normal& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;

    return *this;
}

__inline Normal& Normal::operator-=(const Normal& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;

    return *this;
}
