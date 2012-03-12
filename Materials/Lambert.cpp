/*
 * Lambert.cpp
 *
 *  Created on: 10 Mar 2012
 *      Author: darkip
 */

#include "Lambert.h"
#include "../World.h"
#include "../Utils/ShadeInfo.h"

Colour Lambert::shade(const ShadeInfo& shadeInfo, const World& world) const {
    // Calculate ambient contribution first
    Colour colour = (this->ambientReflection * this->diffuseColour) * world.ambientLight->getRadiance(shadeInfo);

    for (unsigned int i=0; i < world.lights.size(); i++) {
        // Calculate diffuse contribution...

        Vector3 lightDirection = world.lights[i]->getDirection(shadeInfo);
        double NdotL = std::max(0.0, shadeInfo.hitNormal * lightDirection);

        colour += this->diffuseReflection * this->diffuseColour * world.lights[i]->getRadiance(shadeInfo) * NdotL;
    }

    return colour;
}
