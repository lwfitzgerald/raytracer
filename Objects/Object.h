/*
 * Object.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "../Prereqs.h"
#include "../Utils/Colour.h"

class Object {
public:
    Material* material;

    virtual bool hit(const Ray& ray, double& tmin) const = 0;
    virtual void getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const = 0;

    virtual void setMaterial(Material* material) {
        this->material = material;
    }

    virtual ~Object() {};

    static const double epsilon = 0.001;
protected:


    Object() {};

    Object& operator=(const Object& rhs);
};

#endif /* OBJECT_H_ */
