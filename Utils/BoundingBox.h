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

        /**
         * Construct a Bounding Box with the given parameters
         */
        BoundingBox(const Point3& corner1, const Point3& corner2)
        : corner1(corner1), corner2(corner2) {}

        BoundingBox& operator=(const BoundingBox& old);

        /**
         * Intersect a ray with the bounding box returning
         * true if the ray intersects
         */
        bool hit(const Ray& ray) const;

        ~BoundingBox() {}
    };
}

#endif /* BOUNDINGBOX_H_ */
