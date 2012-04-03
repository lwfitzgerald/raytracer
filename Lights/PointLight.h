#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "Light.h"
#include "../Utils/Point3.h"

namespace Raytracer {
    class PointLight: public Light {
    public:
        PointLight();

        /**
         * Construct a Point Light from an istringstream
         */
        PointLight(std::istringstream& iss);
        virtual ~PointLight() {}

        virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const;
        virtual Vector3 getDirectionToHitPoint(const ShadeInfo& shadeInfo) const;
        virtual Colour getRadiance(const ShadeInfo& shadeInfo) const;

        /**
         * Set the position of the Point Light
         */
        void setPosition(const Point3& position);

        virtual bool inShadow(const ShadeInfo& shadeInfo, const World& world) const;

    protected:
        Point3 position;
    };
}

#endif /* POINTLIGHT_H_ */
