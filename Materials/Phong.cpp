#include "Phong.h"
#include "../World.h"
#include "../Utils/ShadeInfo.h"

Phong::Phong(std::istringstream& iss)
: Material(iss) {
    iss >> specularReflection;

    iss >> name;
}

Colour Phong::shade(
    const ShadeInfo& shadeInfo,
    const World& world,
    const unsigned int depth
) const {
    // Calculate ambient contribution first
    Colour colour = (ambientReflection * diffuseColour) * world.ambientLight->getRadiance(shadeInfo);

    for (unsigned int i=0; i < world.lights.size(); i++) {
        // Calculate diffuse contribution...

        Vector3 lightDirection = world.lights[i]->getDirection(shadeInfo);

        double NdotL = shadeInfo.hitNormal * lightDirection;

        if (NdotL > 0) {
            colour += diffuseReflection * diffuseColour * world.lights[i]->getRadiance(shadeInfo) * NdotL;
        }

        // Calculate specular contribution...

        // Calculate reflection vector
        Vector3 R = lightDirection - 2.0 * (lightDirection * shadeInfo.hitNormal) * shadeInfo.hitNormal;

        colour += specularReflection * world.lights[i]->getRadiance(shadeInfo)
                * pow(std::max(0.0, R * shadeInfo.ray.direction), 100);

        // Add contribution from reflections
        if (depth != MAX_TRACE_DEPTH) {
            ShadeInfo reflectInfo = world.hitObjects(
                shadeInfo.ray.getReflectedRay(shadeInfo.hitPoint, shadeInfo.hitNormal),
                depth+1
            );

            if (reflectInfo.hit) {
                colour += specularReflection * reflectInfo.colour;
            }
        }
    }

    return colour;
}
