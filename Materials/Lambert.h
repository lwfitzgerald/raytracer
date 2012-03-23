/*
 * Lambert.h
 *
 *  Created on: 10 Mar 2012
 *      Author: darkip
 */

#ifndef LAMBERT_H_
#define LAMBERT_H_

#include "Material.h"

class Lambert: public Material {
public:
    Lambert() {}
    virtual ~Lambert() {}

    virtual Colour shade(
        const ShadeInfo& shadeInfo,
        const World& world,
        const unsigned int depth
    ) const;
};

#endif /* LAMBERT_H_ */
