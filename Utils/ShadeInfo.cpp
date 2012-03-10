/*
 * ShadeInfo.cpp
 *
 *  Created on: 24 Feb 2012
 *      Author: darkip
 */

#include "ShadeInfo.h"

ShadeInfo& ShadeInfo::operator=(const ShadeInfo& rhs) {
    this->hit = rhs.hit;
    this->hitPoint = rhs.hitPoint;
    this->hitNormal = rhs.hitNormal;
    this->colour = rhs.colour;

    return *this;
}
