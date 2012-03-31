#ifndef LAMBERT_H_
#define LAMBERT_H_

#include "Material.h"

class Lambert: public Material {
public:
    Lambert() {}
    Lambert(std::istringstream& iss);

    virtual ~Lambert() {}

    virtual Colour shade(
        const ShadeInfo& shadeInfo,
        const World& world,
        const unsigned int depth
    ) const;
};

#endif /* LAMBERT_H_ */
