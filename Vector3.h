/*
 * Vector3.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

class Vector3 {
public:
    double x;
    double y;
    double z;

    Vector3();
    Vector3(const double x, const double y, const double z);
    Vector3(const Vector3& old);
    ~Vector3();

    Vector3 operator-();

    Vector3 operator+(const Vector3& other);
    Vector3 operator-(const Vector3& other);
    Vector3& operator=(const Vector3& rhs);

    Vector3 operator*(const double scalar);

    Vector3& operator+=(const Vector3& other);
    Vector3& operator-=(const Vector3& other);

    double mag();
    double magsqr();

    double dot(const Vector3& other);
    Vector3 cross(const Vector3& other);

    void normalise();
    Vector3 hat();
};

#endif /* VECTOR3_H_ */
