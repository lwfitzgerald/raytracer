/*
 * PointLight.cpp
 *
 *  Created on: 12 Mar 2012
 *      Author: darkip
 */

#include "PointLight.h"
#include "../Utils/ShadeInfo.h"

PointLight::PointLight()
: Light() {
    this->castsShadows = true;
}

Vector3 PointLight::getDirection(const ShadeInfo& shadeInfo) const {
    return (this->location - shadeInfo.hitPoint).hat();
}

Colour PointLight::getRadiance(const ShadeInfo& shadeInfo) const {
    return this->colour * this->intensity;
}
