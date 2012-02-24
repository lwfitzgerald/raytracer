/*
 * ShadeInfo.h
 *
 *  Created on: 24 Feb 2012
 *      Author: darkip
 */

#ifndef SHADEINFO_H_
#define SHADEINFO_H_

#include "Prereqs.h"

#include "Point3.h"
#include "Normal.h"
#include "Colour.h"

class ShadeInfo {
public:
    bool hit;
    Point3 hitPoint;
    Normal hitNormal;
    Colour colour;

    ShadeInfo()
    : hit(false), hitPoint(), hitNormal(), colour() {}

    ~ShadeInfo() {}

    ShadeInfo& operator=(const ShadeInfo& rhs);
};

#endif /* SHADEINFO_H_ */
