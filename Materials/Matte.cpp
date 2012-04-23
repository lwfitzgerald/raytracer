#include "Matte.h"
#include "../World.h"
#include "../Utils/ShadeInfo.h"

namespace Raytracer {
    Matte::Matte(std::istringstream& iss)
    : Material(iss) {
        iss >> name;
    }

    Colour Matte::shade(
        const ShadeInfo& shadeInfo,
        const World& world,
        const unsigned int depth
    ) const {
        // Calculate ambient contribution first
        Colour colour = ambientReflection * diffuseColour * world.ambientLight->getRadiance(shadeInfo);

        for (unsigned int i=0; i < world.lights.size(); i++) {
            // Calculate diffuse contribution...

            Vector3 lightDirection = world.lights[i]->getDirection(shadeInfo);
            double NdotL = shadeInfo.hitNormal * -lightDirection;

            if (NdotL > 0) {
                if (!world.lights[i]->inShadow(shadeInfo, world)) {
                    colour += diffuseReflection * diffuseColour * world.lights[i]->getRadiance(shadeInfo) * NdotL;
                }
            }
        }

        return colour;
    }
}
