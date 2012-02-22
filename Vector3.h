/*
 * Vector3.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include "macros.h"
#include "Normal.h"

#include "math.h"

class Vector3 {
public:
    double x;
    double y;
    double z;

    Vector3() {};

    __inline Vector3(const double x, const double y, const double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    __inline Vector3(const Vector3& old) {
        this->x = old.x;
        this->y = old.y;
        this->z = old.z;
    }

    __inline ~Vector3() {};

    __inline Vector3 operator-() const {
        return Vector3(
            -this->x,
            -this->y,
            -this->z
        );
    }

    __inline Vector3 operator+(const Vector3& other) const {
        return Vector3(
            this->x + other.x,
            this->y + other.y,
            this->z + other.z
        );
    }

    __inline Vector3 operator-(const Vector3& rhs) const {
        return Vector3(
            this->x - rhs.x,
            this->y - rhs.y,
            this->z - rhs.z
        );
    }

    __inline Vector3& operator=(const Vector3& rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;

        return *this;
    }

    __inline Vector3 operator*(const double other) const {
        return Vector3(
            other * this->x,
            other * this->y,
            other * this->z
        );
    }

    __inline Vector3& operator+=(const Vector3& rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;

        return *this;
    }

    __inline Vector3& operator-=(const Vector3& rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;

        return *this;
    }

    __inline double mag() const {
        return sqrt(sqr(this->x) + sqr(this->y) + sqr(this->z));
    }

    __inline double magsqr() const {
        return sqr(this->x) + sqr(this->y) + sqr(this->z);
    }

    __inline double dot(const Vector3& rhs) const {
        return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
    }

    __inline double dot(const Normal& rhs) const {
        return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
    }

    __inline Vector3 cross(const Vector3& other) const {
        return Vector3(
            this->y * other.z + this->z * other.y,
            this->z * other.x + this->x * other.z,
            this->x * other.y + this->y * other.x
        );
    }

    __inline void normalise() {
        double length = this->mag();

        if (length > 0) {
            double inverseLength = 1.0 / length;
            this->x *= inverseLength;
            this->y *= inverseLength;
            this->z *= inverseLength;
        }
    }

    __inline Vector3 hat() const {
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
};

#endif /* VECTOR3_H_ */
