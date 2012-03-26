#ifndef AMBIENTLIGHT_H_
#define AMBIENTLIGHT_H_

#include "Light.h"

class AmbientLight: public Light {
public:
    AmbientLight();

    virtual ~AmbientLight() {}

    virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const;
    virtual Colour getRadiance(const ShadeInfo& shadeInfo) const;
};

#endif /* AMBIENTLIGHT_H_ */
