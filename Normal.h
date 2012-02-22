/*
 * Normal.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef NORMAL_H_
#define NORMAL_H_

#include "Vector3.h"

class Normal {
public:
    double x;
    double y;
    double z;

    __inline Normal() {}

    __inline Normal(const double x, const double y, const double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    __inline Normal(const Normal& old) {
        this->x = old.x;
        this->y = old.y;
        this->z = old.z;
    }

    __inline ~Normal() {}

    __inline Normal operator-() {
        return Normal(
            -this->x,
            -this->y,
            -this->z
        );
    }

    __inline Normal operator+(const Normal& other) {
        return Normal(
            this->x + other.x,
            this->y + other.y,
            this->z + other.z
        );
    }

    __inline Vector3 operator+(const Vector3& other) {
        return Vector3(
            this->x + other.x,
            this->y + other.y,
            this->z + other.z
        );
    }

    __inline Normal operator*(const double a) {
        return Normal(
            a * this->x,
            a * this->y,
            a * this->z
        );
    }

    __inline Normal& operator=(const Normal& rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;

        return *this;
    }

    __inline Normal& operator+=(const Normal& rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;

        return *this;
    }

    __inline Normal& operator-=(const Normal& rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;

        return *this;
    }

    __inline double dot(const Vector3& rhs) {
        return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
    }
};

#endif /* NORMAL_H_ */
