#include "ShadeInfo.h"

namespace Raytracer {
    ShadeInfo& ShadeInfo::operator=(const ShadeInfo& rhs) {
        hit = rhs.hit;
        ray = rhs.ray;
        hitPoint = rhs.hitPoint;
        hitNormal = rhs.hitNormal;
        hitObject = rhs.hitObject;
        colour = rhs.colour;
        normalFlipped = rhs.normalFlipped;

        return *this;
    }
}
