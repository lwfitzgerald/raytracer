#ifndef PHONG_H_
#define PHONG_H_

#include "Material.h"

namespace Raytracer {
    class Phong: public Material {
    public:
        double specularReflection;
        double distribution;

        Phong() {}

        Phong(std::istringstream& iss);

        virtual ~Phong() {}

        virtual Colour shade(
            const ShadeInfo& shadeInfo,
            const World& world,
            const unsigned int depth
        ) const;

        void setSpecularReflection(const double& specularReflection);

        void setDistribution(const double& distribution);

    protected:
        /**
         * Shade using the provided specular reflection
         * coefficient to allow transparency class to
         * use fresnel equations to calculate reflection
         * coefficient
         */
        Colour shade(
            const double& specularReflection,
            const ShadeInfo& shadeInfo,
            const World& world,
            const unsigned int depth
        ) const;
    };
}

#endif /* PHONG_H_ */
