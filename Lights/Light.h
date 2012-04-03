#ifndef LIGHT_H_
#define LIGHT_H_

#include "../Prereqs.h"

#include "../Utils/Vector3.h"
#include "../Utils/Colour.h"

namespace Raytracer {
    class Light {
    public:
        virtual ~Light() {}

        virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const = 0;
        virtual Vector3 getDirectionToHitPoint(const ShadeInfo& shadeInfo) const = 0;
        virtual Colour getRadiance(const ShadeInfo& shadeInfo) const = 0;

        void setIntensity(const double& intensity) {
            this->intensity = intensity;
        }

        void setColour(const Colour& colour) {
            this->colour = colour;
        }

        bool castsShadows() const {
            return mCastsShadows;
        }

        virtual bool inShadow(const ShadeInfo& shadeInfo, const World& world) const = 0;

    protected:
        double intensity;
        Colour colour;

        bool mCastsShadows;

        Light()
        :
            intensity(1),
            colour(WHITE) {}

        Light(std::istringstream& iss) {
            double r, g, b;

            iss >> r;
            iss >> g;
            iss >> b;

            iss >> intensity;

            colour = Colour(r, g, b);
        }
    };
}

#endif /* LIGHT_H_ */
