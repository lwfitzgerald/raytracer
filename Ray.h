/*
 * Ray.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef RAY_H_
#define RAY_H_

class Point3;
class Vector3;

class Ray {
public:
    Ray();
    Ray(const Point3 origin, const Vector3& direction);
    Ray(const Ray& old);
    ~Ray();

    Ray& operator=(const Ray& rhs);
};

#endif /* RAY_H_ */
