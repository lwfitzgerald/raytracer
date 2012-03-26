#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "Light.h"
#include "../Utils/Point3.h"

class PointLight: public Light {
public:
    PointLight();
    virtual ~PointLight() {}

    virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const;
    virtual Colour getRadiance(const ShadeInfo& shadeInfo) const;

    void setLocation(const Point3& location);

private:
    Point3 location;
};

#endif /* POINTLIGHT_H_ */
