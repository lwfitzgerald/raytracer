/*
 * DirectionalLight.h
 *
 *  Created on: 10 Mar 2012
 *      Author: darkip
 */

#ifndef DIRECTIONALLIGHT_H_
#define DIRECTIONALLIGHT_H_

#include "Light.h"

class DirectionalLight : public Light {
public:
    DirectionalLight();
    virtual ~DirectionalLight() {}

    virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const;
    virtual Colour getRadiance(const ShadeInfo& shadeInfo) const;

    void setDirection(const Vector3& direction) {
        this->direction = direction.hat();
    }

    Vector3 getDirection() const {
        return this->direction;
    }
private:
    Vector3 direction;
};

#endif /* DIRECTIONALLIGHT_H_ */
