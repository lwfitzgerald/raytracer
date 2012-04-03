#ifndef TRANSPARENT_H_
#define TRANSPARENT_H_

#include "Phong.h"

namespace Raytracer {
    class Transparent : public Phong {
    public:
        /**
         * Index of refraction
         */
        double ior;

        Transparent() {}

        /**
         * Construct a Transparent material from an istringstream
         */
        Transparent(std::istringstream& iss);

        virtual ~Transparent() {}

        virtual Colour shade(
            const ShadeInfo& shadeInfo,
            const World& world,
            const unsigned int depth
        ) const;

        /**
         * Set the index of refraction
         */
        void setIndexOfRefraction(const double& ior);
    };
}

#endif /* TRANSPARENT_H_ */
