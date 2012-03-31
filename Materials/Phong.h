#ifndef PHONG_H_
#define PHONG_H_

#include "Material.h"

class Phong: public Material {
public:
    double specularReflection;

    Phong()
    :
        specularReflection(1) {}

    Phong(std::istringstream& iss);

    virtual ~Phong() {}

    virtual Colour shade(
        const ShadeInfo& shadeInfo,
        const World& world,
        const unsigned int depth
    ) const;

    void setSpecularReflection(const double& specularReflection) {
        this->specularReflection = specularReflection;
    }
};

#endif /* PHONG_H_ */
