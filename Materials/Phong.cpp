/*
 * Phong.cpp
 *
 *  Created on: 11 Mar 2012
 *      Author: darkip
 */

#include "Phong.h"
#include "../World.h"
#include "../Utils/ShadeInfo.h"

Colour Phong::shade(const ShadeInfo& shadeInfo, const World& world) const {
    // Calculate ambient contribution first
    Colour colour = (this->ambientReflection * this->diffuseColour) * world.ambientLight->getRadiance(shadeInfo);

    for (unsigned int i=0; i < world.lights.size(); i++) {
        // Calculate diffuse contribution...

        Vector3 lightDirection = world.lights[i]->getDirection(shadeInfo);

        double NdotL = shadeInfo.hitNormal * lightDirection;

        if (NdotL > 0) {
            colour += this->specularReflection * this->diffuseColour * world.lights[i]->getRadiance(shadeInfo) * NdotL;
        }

        // Calculate specular contribution...

        // Calculate reflection vector
        Vector3 R = lightDirection - 2.0 * (lightDirection * shadeInfo.hitNormal) * shadeInfo.hitNormal;

        colour += this->diffuseReflection * world.lights[i]->getRadiance(shadeInfo)
                * pow(std::max(0.0, R * shadeInfo.ray.direction), 100);
    }

    return colour;
}
