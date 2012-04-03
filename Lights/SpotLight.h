#ifndef SPOTLIGHT_H_
#define SPOTLIGHT_H_

#include "../Prereqs.h"
#include "PointLight.h"

namespace Raytracer {
    class SpotLight: public PointLight {
    public:
        Vector3 direction;
        double rateOfFallOff;

        SpotLight() {}
        SpotLight(std::istringstream& iss);
        virtual ~SpotLight() {}

        virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const;
        virtual Vector3 getDirectionToHitPoint(const ShadeInfo& shadeInfo) const;
        virtual Colour getRadiance(const ShadeInfo& shadeInfo) const;

        void setDirection(const Vector3& direction);
        void setRateOfFallOff(const double& rateOfFallOff);

        virtual bool inShadow(const ShadeInfo& shadeInfo, const World& world) const;
    };
}

#endif /* SPOTLIGHT_H_ */
