#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_

#include "../Prereqs.h"
#include "Point3.h"

namespace Raytracer {
    class BoundingBox {
    public:
        Point3 corner1;
        Point3 corner2;

        BoundingBox() {}

        BoundingBox(const Point3& corner1, const Point3& corner2)
        : corner1(corner1), corner2(corner2) {}

        BoundingBox& operator=(const BoundingBox& old);

        ~BoundingBox() {}
    };
}

#endif /* BOUNDINGBOX_H_ */
