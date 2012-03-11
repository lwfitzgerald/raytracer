/*
 * DirectionalLight.cpp
 *
 *  Created on: 10 Mar 2012
 *      Author: darkip
 */

#include "DirectionalLight.h"
#include "../Utils/ShadeInfo.h"

DirectionalLight::DirectionalLight()
: Light() {
    // Directional lights cause shadows
    this->castsShadows = true;
}

Vector3 DirectionalLight::getDirection(const ShadeInfo& shadeInfo) const {
    return direction;
}

Colour DirectionalLight::getRadiance(const ShadeInfo& shadeInfo) const {
    return this->colour * this->intensity;
}
