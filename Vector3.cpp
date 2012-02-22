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

__inline Vector3 Vector3::operator+(const Vector3& other) {
    return Vector3(
        this->x + other.x,
        this->y + other.y,
        this->z + other.z
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

__inline Vector3 Vector3::operator*(const double other) {
    return Vector3(
        other * this->x,
        other * this->y,
        other * this->z
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

__inline double Vector3::dot(const Vector3& other) {
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

__inline Vector3 Vector3::cross(const Vector3& other) {
    return Vector3(
        this->y * other.z + this->z * other.y,
        this->z * other.x + this->x * other.z,
        this->x * other.y + this->y * other.x
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
