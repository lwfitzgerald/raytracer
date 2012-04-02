#include "Transparent.h"
#include "../Utils/Ray.h"
#include "../Utils/ShadeInfo.h"
#include "../World.h"

namespace Raytracer {
    Transparent::Transparent(std::istringstream& iss) {
        initMaterial(iss);

        iss >> specularReflection;

        iss >> name;
    }

    Colour Transparent::shade(
        const ShadeInfo& shadeInfo,
        const World& world,
        const unsigned int depth
    ) const {
        // Use Phong shading first
        Colour colour = Phong::shade(shadeInfo, world, depth);

        double reflectionCoeff, transmitCoeff;
        Ray refractedRay;
        bool refractedExists;

        refractedExists = shadeInfo.ray.getTransparentDetails(shadeInfo,
            reflectionCoeff, transmitCoeff, refractedRay);

        Ray reflectedRay = shadeInfo.ray.getReflectedRay(shadeInfo);
        if (depth != MAX_TRACE_DEPTH) {
            if (refractedExists) {
                ShadeInfo refractInfo = world.hitObjects(refractedRay, depth+1);

                if (refractInfo.hit) {
                    colour += transmitCoeff * refractInfo.colour;
                }
            }
        }

        return colour;
    }
}
