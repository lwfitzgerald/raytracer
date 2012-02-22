/*
 * Normal.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef NORMAL_H_
#define NORMAL_H_

#include "Prereqs.h"

class Normal {
public:
    double x;
    double y;
    double z;

    __inline Normal() {}

    __inline Normal(const double x, const double y, const double z)
    : x(x), y(y), z(z) {}

    __inline Normal(const Normal& old)
    : x(old.x), y(old.y), z(old.z) {}

    __inline ~Normal() {}

    Normal operator-() const;

    Normal operator+(const Normal& other) const;
    Vector3 operator+(const Vector3& other) const;

    // Scalar mult
    __inline friend Normal operator*(const double lhs, const Normal& rhs) {
        return rhs * lhs;
    }
    Normal operator*(const double& rhs) const;

    double operator*(const Vector3& other) const;

    Normal& operator=(const Normal& rhs);

    Normal& operator+=(const Normal& rhs);

    Normal& operator-=(const Normal& rhs);
};

#endif /* NORMAL_H_ */
