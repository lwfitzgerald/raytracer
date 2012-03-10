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
    Colour colour = (this->diffuseReflection * this->diffuseColour) * world.ambientLight->getIllumination(shadeInfo);

    // Then add contributions from other lights

    for (unsigned int i=0; i < world.lights.size(); i++) {
        Vector3 lightDirection = world.lights[i]->getDirection(shadeInfo);
        double NdotL = shadeInfo.hitNormal * lightDirection;

        if (NdotL > 0) {
            // Not self occlusion so contribution!
            colour += (this->diffuseReflection * this->diffuseColour * INV_PI) * world.lights[i]->getIllumination(shadeInfo) * NdotL;
        }
    }

    return colour;
}
