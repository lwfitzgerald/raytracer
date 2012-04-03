#ifndef MATTE_H_
#define MATTE_H_

#include "Material.h"

namespace Raytracer {
    class Matte: public Material {
    public:
        Matte() {}

        /**
         * Construct a Matte material from an istringstream
         */
        Matte(std::istringstream& iss);

        virtual ~Matte() {}

        virtual Colour shade(
            const ShadeInfo& shadeInfo,
            const World& world,
            const unsigned int depth
        ) const;
    };
}

#endif /* MATTE_H_ */
