/*
 * Camera.h
 *
 *  Created on: 29 Feb 2012
 *      Author: darkip
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Prereqs.h"

#include "Point3.h"
#include "Vector3.h"

class Camera {
public:
    Camera()
    :
        eye(0.0, 0, 350.0),
        lookAt(0.0, 0.0, 0.0),
        up(0.0, 1.0, 0.0),
        u(1.0, 0.0, 0.0),
        v(0.0, 1.0, 0.0),
        w(0.0, 0.0, 1.0) {}

    virtual ~Camera() {}

    virtual void renderScene(World& world) const = 0;

    void setEyePoint(const Point3& point);
    void setLookAtPoint(const Point3& point);
    void setUpVector(const Vector3& vector);

    void calcUVW();

protected:
    Point3 eye;
    Point3 lookAt;
    Vector3 up;
    Vector3 u;
    Vector3 v;
    Vector3 w;
};

#endif /* CAMERA_H_ */
