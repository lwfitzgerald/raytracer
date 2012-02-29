/*
 * Camera.cpp
 *
 *  Created on: 29 Feb 2012
 *      Author: darkip
 */

#include "Camera.h"

void Camera::setEyePoint(const Point3& point) {
    this->eye = point;
}

void Camera::setLookAtPoint(const Point3& point) {
    this->lookAt = point;
}

void Camera::setUpVector(const Vector3& vector) {
    this->up = vector;
}

void Camera::calcUVW() {
    this->w = this->eye - this->lookAt;
    this->w.normalise();
    this->u = this->up.cross(this->w);
    this->u.normalise();
    this->v = this->w.cross(this->u);
}
