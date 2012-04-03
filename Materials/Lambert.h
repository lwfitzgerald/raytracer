#ifndef LAMBERT_H_
#define LAMBERT_H_

#include "Material.h"

namespace Raytracer {
    class Lambert: public Material {
    public:
        Lambert() {}

        /**
         * Construct a Lambert material from an istringstream
         */
        Lambert(std::istringstream& iss);

        virtual ~Lambert() {}

        virtual Colour shade(
            const ShadeInfo& shadeInfo,
            const World& world,
            const unsigned int depth
        ) const;
    };
}

#endif /* LAMBERT_H_ */
