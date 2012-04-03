#ifndef SPOTLIGHT_H_
#define SPOTLIGHT_H_

#include "../Prereqs.h"
#include "PointLight.h"

namespace Raytracer {
    class SpotLight: public PointLight {
    public:
        SpotLight() {}

        /**
         * Construct a Spot Light from an istringstream
         */
        SpotLight(std::istringstream& iss);

        virtual ~SpotLight() {}

        virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const;
        virtual Vector3 getDirectionToHitPoint(const ShadeInfo& shadeInfo) const;
        virtual Colour getRadiance(const ShadeInfo& shadeInfo) const;

        /**
         * Set the direction of the Spot Light
         */
        void setDirection(const Vector3& direction);

        /**
         * Set the rate of falloff of the Spot Light
         */
        void setRateOfFallOff(const double& rateOfFallOff);

        virtual bool inShadow(const ShadeInfo& shadeInfo, const World& world) const;

    private:
        Vector3 direction;
        double rateOfFallOff;
    };
}

#endif /* SPOTLIGHT_H_ */
