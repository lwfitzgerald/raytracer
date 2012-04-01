#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "Light.h"
#include "../Utils/Point3.h"

namespace Raytracer {
    class PointLight: public Light {
    public:
        PointLight();
        PointLight(std::istringstream& iss);
        virtual ~PointLight() {}

        virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const;
        virtual Colour getRadiance(const ShadeInfo& shadeInfo) const;

        void setPosition(const Point3& position);

    private:
        Point3 position;
    };
}

#endif /* POINTLIGHT_H_ */
