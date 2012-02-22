/*
 * Point.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef POINT_H_
#define POINT_H_

#include "Vector3.h"

class Point {
public:
    double x;
    double y;
    double z;

    Point();
    Point(const double x, const double y, const double z);
    Point(const Point & old);
    ~Point();

    Point operator-();

    Point operator+(const Vector3& rhs);
    Point operator-(const Vector3& rhs);
    Vector3 operator-(const Point& rhs);
    Point& operator=(const Point& rhs);

    Vector3 operator*(const double a);

    Vector3& operator+=(const Vector3& rhs);
    Vector3& operator-=(const Vector3& rhs);
};

#endif /* POINT_H_ */
