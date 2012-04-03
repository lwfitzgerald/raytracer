#ifndef LIGHT_H_
#define LIGHT_H_

#include "../Prereqs.h"

#include "../Utils/Vector3.h"
#include "../Utils/Colour.h"

namespace Raytracer {
    class Light {
    public:
        virtual ~Light() {}

        /**
         * Get the direction of the light
         */
        virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const = 0;

        /**
         * Get the direction of light towards the hit point
         */
        virtual Vector3 getDirectionToHitPoint(const ShadeInfo& shadeInfo) const = 0;

        /**
         * Get the radiance of the light for a given hit point
         */
        virtual Colour getRadiance(const ShadeInfo& shadeInfo) const = 0;

        /**
         * Set the intensity of the light
         */
        void setIntensity(const double& intensity) {
            this->intensity = intensity;
        }

        /**
         * Set the diffuse colour of the light
         */
        void setColour(const Colour& colour) {
            this->colour = colour;
        }

        /**
         * Return whether the light casts shadows or not
         */
        bool castsShadows() const {
            return mCastsShadows;
        }

        /**
         * Return whether the hit point provided is in shadow
         * from this light. Returns true if in shadow.
         */
        virtual bool inShadow(const ShadeInfo& shadeInfo, const World& world) const = 0;

    protected:
        double intensity;
        Colour colour;

        bool mCastsShadows;

        Light()
        :
            intensity(1),
            colour(WHITE) {}

        /**
         * Create a light from an istringstream
         */
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
