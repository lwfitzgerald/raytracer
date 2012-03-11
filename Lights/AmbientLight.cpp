/*
 * AmbientLight.cpp
 *
 *  Created on: 10 Mar 2012
 *      Author: darkip
 */

#include "AmbientLight.h"

AmbientLight::AmbientLight()
: Light() {
    // Ambient lights don't cause shadows
    this->castsShadows = false;
}

Vector3 AmbientLight::getDirection(const ShadeInfo& shadeInfo) const {
    return Vector3(0.0, 0.0, 0.0);
}

Colour AmbientLight::getRadiance(const ShadeInfo& shadeInfo) const {
    return this->colour * this->intensity;
}
