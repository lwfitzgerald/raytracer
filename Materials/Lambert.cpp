#include "Lambert.h"
#include "../World.h"
#include "../Utils/ShadeInfo.h"

Lambert::Lambert(std::istringstream& iss)
: Material(iss) {
    iss >> name;
}

Colour Lambert::shade(
    const ShadeInfo& shadeInfo,
    const World& world,
    const unsigned int depth
) const {
    // Calculate ambient contribution first
    Colour colour = (ambientReflection * diffuseColour) * world.ambientLight->getRadiance(shadeInfo);

    for (unsigned int i=0; i < world.lights.size(); i++) {
        // Calculate diffuse contribution...

        Vector3 lightDirection = world.lights[i]->getDirection(shadeInfo);
        double NdotL = std::max(0.0, shadeInfo.hitNormal * lightDirection);

        colour += diffuseReflection * diffuseColour * world.lights[i]->getRadiance(shadeInfo) * NdotL;
    }

    return colour;
}
