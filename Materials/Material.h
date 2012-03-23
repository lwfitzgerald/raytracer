/*
 * Material.h
 *
 *  Created on: 10 Mar 2012
 *      Author: darkip
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "../Prereqs.h"
#include "../Utils/Colour.h"

class Material {
public:
    Colour diffuseColour;
    double ambientReflection;
    double diffuseReflection;

    virtual ~Material() {}

    virtual Colour shade(
        const ShadeInfo& shadeInfo,
        const World& world,
        const unsigned int depth
    ) const = 0;

    void setDiffuseColour(const Colour& diffuseColour) {
        this->diffuseColour = diffuseColour;
    }

    void setAmbientReflection(const double& ambientReflection) {
        this->ambientReflection = ambientReflection;
    }

    void setDiffuseReflection(const double& diffuseReflection) {
        this->diffuseReflection = diffuseReflection;
    }

protected:
    Material() {}
};

#endif /* MATERIAL_H_ */
