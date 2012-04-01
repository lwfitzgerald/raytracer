#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "../Prereqs.h"
#include "../Utils/Colour.h"

namespace Raytracer {
    class Material {
    public:
        std::string name;
        Colour diffuseColour;
        double ambientReflection;
        double diffuseReflection;

        virtual ~Material() {}

        virtual Colour shade(
            const ShadeInfo& shadeInfo,
            const World& world,
            const unsigned int depth
        ) const = 0;

        void setDiffuseColour(const Colour& diffuseColour) {
            this->diffuseColour = diffuseColour;
        }

        void setAmbientReflection(const double& ambientReflection) {
            this->ambientReflection = ambientReflection;
        }

        void setDiffuseReflection(const double& diffuseReflection) {
            this->diffuseReflection = diffuseReflection;
        }

    protected:
        Material() {}

        /**
         * Constructs the material from an input string.
         *
         * WARNING - Does not store name to allow
         * for a variable number of parameters in child
         * classes.
         *
         * Child classes extending should have the following
         * as the last line:
         *
         * iss >> name;
         */
        Material(std::istringstream& iss) {
            double r, g, b;

            iss >> r;
            iss >> g;
            iss >> b;

            iss >> ambientReflection;
            iss >> diffuseReflection;

            diffuseColour = Colour(r, g, b);
        }
    };
}

#endif /* MATERIAL_H_ */
