/*
 * Light.h
 *
 *  Created on: 10 Mar 2012
 *      Author: darkip
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "../Prereqs.h"

#include "../Utils/Vector3.h"
#include "../Utils/Colour.h"

class Light {
public:
    virtual ~Light() {}

    virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const = 0;
    virtual Colour getIllumination(const ShadeInfo& shadeInfo) const = 0;

    void setIntensity(const double& intensity) {
        this->intensity = intensity;
    }

    void setColour(const Colour& colour) {
        this->colour = colour;
    }

protected:
    Light()
    :
        intensity(1),
        colour(WHITE) {}

    double intensity;
    Colour colour;

    bool castsShadows;
};

#endif /* LIGHT_H_ */
