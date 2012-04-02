#ifndef TRANSPARENT_H_
#define TRANSPARENT_H_

#include "Phong.h"

namespace Raytracer {
    class Transparent : public Phong {
    public:
        Transparent() {}
        Transparent(std::istringstream& iss);

        virtual ~Transparent() {}

        virtual Colour shade(
            const ShadeInfo& shadeInfo,
            const World& world,
            const unsigned int depth
        ) const;
    };
}

#endif /* TRANSPARENT_H_ */
