#include "BoundingBox.h"

namespace Raytracer {
    BoundingBox& BoundingBox::operator=(const BoundingBox& old) {
        corner1 = old.corner1;
        corner2 = old.corner2;

        return *this;
    }
}
