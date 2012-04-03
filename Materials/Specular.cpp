#include "Specular.h"
#include "../World.h"
#include "../Utils/ShadeInfo.h"

namespace Raytracer {
    Specular::Specular(std::istringstream& iss)
    : Material(iss) {
        iss >> specularReflection;
        iss >> distribution;

        iss >> name;
    }

    Colour Specular::shade(
        const ShadeInfo& shadeInfo,
        const World& world,
        const unsigned int depth
    ) const {
        return shade(specularReflection, shadeInfo, world, depth);
    }

    Colour Specular::shade(
        const double& specularReflection,
        const ShadeInfo& shadeInfo,
        const World& world,
        const unsigned int depth
    ) const {
        // Calculate ambient contribution first
        Colour colour = (ambientReflection * diffuseColour) * world.ambientLight->getRadiance(shadeInfo);

        for (unsigned int i=0; i < world.lights.size(); i++) {
            // Calculate diffuse contribution...

            Vector3 lightDirection = world.lights[i]->getDirection(shadeInfo);

            double NdotL = shadeInfo.hitNormal * -lightDirection;

            if (NdotL > 0) {
                if (!world.lights[i]->inShadow(shadeInfo, world)) {
                    colour += diffuseReflection * diffuseColour * world.lights[i]->getRadiance(shadeInfo) * NdotL;

                    // Calculate specular contribution...

                    // Calculate reflection vector
                    Vector3 R = -lightDirection - 2.0 * (-lightDirection * shadeInfo.hitNormal) * shadeInfo.hitNormal;

                    colour += specularReflection * world.lights[i]->getRadiance(shadeInfo)
                            * std::pow(std::max(0.0, R * shadeInfo.ray.direction), distribution);
                }
            }

            // Add contribution from reflections
            if (depth != MAX_TRACE_DEPTH) {
                ShadeInfo reflectInfo = world.hitObjects(
                    shadeInfo.ray.getReflectedRay(shadeInfo),
                    depth+1
                );

                if (reflectInfo.hit) {
                    colour += specularReflection * reflectInfo.colour;
                }
            }
        }

        return colour;
    }

    void Specular::setSpecularReflection(const double& specularReflection) {
        this->specularReflection = specularReflection;
    }

    void Specular::setDistribution(const double& distribution) {
        this->distribution = distribution;
    }
}
