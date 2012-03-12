/*
 * Vector3.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#include "../Prereqs.h"

#include "Vector3.h"
#include "Normal.h"

Vector3 Vector3::operator-() const {
    return Vector3(
        -this->x,
        -this->y,
        -this->z
    );
}

Vector3 Vector3::operator+(const Vector3& rhs) const {
    return Vector3(
        this->x + rhs.x,
        this->y + rhs.y,
        this->z + rhs.z
    );
}

Vector3 Vector3::operator-(const Vector3& rhs) const {
    return Vector3(
        this->x - rhs.x,
        this->y - rhs.y,
        this->z - rhs.z
    );
}

Vector3 Vector3::operator-(const Normal& rhs) const {
    return Vector3(
        this->x - rhs.x,
        this->y - rhs.y,
        this->z - rhs.z
    );
}

Vector3& Vector3::operator=(const Vector3& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;

    return *this;
}

Vector3 Vector3::operator*(const double& rhs) const {
    return Vector3(
        rhs * this->x,
        rhs * this->y,
        rhs * this->z
    );
}

Vector3 Vector3::operator/(const double& rhs) const {
    return Vector3(
        this->x / rhs,
        this->y / rhs,
        this->z / rhs
    );
}

double Vector3::operator*(const Normal& rhs) const {
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

Vector3& Vector3::operator+=(const Vector3& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;

    return *this;
}

double Vector3::operator*(const Vector3& rhs) const {
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

double Vector3::mag() const {
    return sqrt(sqr(this->x) + sqr(this->y) + sqr(this->z));
}

double Vector3::magsqr() const {
    return sqr(this->x) + sqr(this->y) + sqr(this->z);
}

Vector3 Vector3::cross(const Vector3& rhs) const {
    return Vector3(
        this->y * rhs.z - this->z * rhs.y,
        this->z * rhs.x - this->x * rhs.z,
        this->x * rhs.y - this->y * rhs.x
    );
}

void Vector3::normalise() {
    double length = this->mag();

    if (length > 0) {
        double inverseLength = 1.0 / length;
        this->x *= inverseLength;
        this->y *= inverseLength;
        this->z *= inverseLength;
    }
}

Vector3 Vector3::hat() const {
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
