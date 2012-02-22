/*
 * Vector3.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#include "Vector3.h"
#include "math.h"
#include "macros.h"

Vector3::Vector3() {}

Vector3::Vector3(const double x, const double y, const double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::Vector3(const Vector3& old) {
    this->x = old.x;
    this->y = old.y;
    this->z = old.z;
}

Vector3::~Vector3() {}

__inline Vector3 Vector3::operator-() {
    return Vector3(
        -this->x,
        -this->y,
        -this->z
    );
}

__inline Vector3 Vector3::operator+(const Vector3& rhs) {
    return Vector3(
        this->x + rhs.x,
        this->y + rhs.y,
        this->z + rhs.z
    );
}

__inline Vector3 Vector3::operator-(const Vector3& rhs) {
    return Vector3(
        this->x - rhs.x,
        this->y - rhs.y,
        this->z - rhs.z
    );
}

__inline Vector3 &Vector3::operator=(const Vector3& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;

    return *this;
}

__inline Vector3 Vector3::operator*(const double a) {
    return Vector3(
        a * this->x,
        a * this->y,
        a * this->z
    );
}

__inline Vector3& Vector3::operator+=(const Vector3& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;

    return *this;
}

__inline Vector3& Vector3::operator-=(const Vector3& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;

    return *this;
}

__inline double Vector3::mag() {
    return sqrt(sqr(this->x) + sqr(this->y) + sqr(this->z));
}

__inline double Vector3::magsqr() {
    return sqr(this->x) + sqr(this->y) + sqr(this->z);
}

__inline double Vector3::dot(const Vector3 & rhs) {
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

__inline Vector3 Vector3::cross(const Vector3 & rhs) {
    return Vector3(
        this->y * rhs.z + this->z * rhs.y,
        this->z * rhs.x + this->x * rhs.z,
        this->x * rhs.y + this->y * rhs.x
    );
}

__inline void Vector3::normalise() {
    double length = this->mag();

    if (length > 0) {
        double inverseLength = 1.0 / length;
        this->x *= inverseLength;
        this->y *= inverseLength;
        this->z *= inverseLength;
    }
}

__inline Vector3 Vector3::hat() {
    double lengthSqr = this->magsqr();

    Vector3 newVector = *this;

    if (lengthSqr > 0) {
        double inverseLength = 1.0 / sqrt(lengthSqr);

        newVector.x *= inverseLength;
        newVector.y *= inverseLength;
        newVector.z *= inverseLength;
    }

    return newVector;
}
