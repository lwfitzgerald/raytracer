#ifndef SHADEINFO_H_
#define SHADEINFO_H_

#include "../Prereqs.h"

#include "Ray.h"
#include "Point3.h"
#include "Normal.h"
#include "Colour.h"

namespace Raytracer {
    class ShadeInfo {
    public:
        bool hit;
        Ray ray;
        Point3 hitPoint;
        Normal hitNormal;
        Colour colour;
        bool normalFlipped;

        ShadeInfo()
        : hit(false),
          normalFlipped(false) {}

        ~ShadeInfo() {}

        ShadeInfo& operator=(const ShadeInfo& rhs);
    };
}

#endif /* SHADEINFO_H_ */
