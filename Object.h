/*
 * Object.h
 *
 *  Created on: 22 Feb 2012
 *      Author: darkip
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "Prereqs.h"

class Object {
public:
    virtual bool hit(const Ray& ray, double& tmin, ShadeInfo& shadeInfo) const = 0;

    virtual ~Object() {};
protected:
    static const double epsilon = 0.001;

    Object() {};

    Object& operator=(const Object& rhs);
};

#endif /* OBJECT_H_ */
