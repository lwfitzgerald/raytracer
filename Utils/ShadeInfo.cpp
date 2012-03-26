#include "ShadeInfo.h"

ShadeInfo& ShadeInfo::operator=(const ShadeInfo& rhs) {
    hit = rhs.hit;
    ray = rhs.ray;
    hitPoint = rhs.hitPoint;
    hitNormal = rhs.hitNormal;
    colour = rhs.colour;

    return *this;
}
