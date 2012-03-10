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
    Colour colour;

    virtual bool hit(const Ray& ray, double& tmin) const = 0;
    virtual void getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const = 0;

    virtual ~Object() {};
protected:
    static const double epsilon = 0.001;

    Object() {};

    Object& operator=(const Object& rhs);
};

#endif /* OBJECT_H_ */
