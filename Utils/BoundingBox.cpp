#include "BoundingBox.h"
#include "Ray.h"

namespace Raytracer {
    bool BoundingBox::hit(const Ray& ray) const {
        // This code is closely derived from that in
        // Raytracing from the ground up

        double tXmin, tYmin, tZmin;
        double tXmax, tYmax, tZmax;

        if (ray.direction.x >= 0) {
            tXmin = (corner1.x - ray.origin.x) / ray.direction.x;
            tXmax = (corner2.x - ray.origin.x) / ray.direction.x;
        } else {
            tXmin = (corner2.x - ray.origin.x) / ray.direction.x;
            tXmax = (corner1.x - ray.origin.x) / ray.direction.x;
        }

        if (ray.direction.y >= 0) {
            tYmin = (corner1.y - ray.origin.y) / ray.direction.y;
            tYmax = (corner2.y - ray.origin.y) / ray.direction.y;
        } else {
            tYmin = (corner2.y - ray.origin.y) / ray.direction.y;
            tYmax = (corner1.y - ray.origin.y) / ray.direction.y;
        }

        if (ray.direction.z >= 0) {
            tZmin = (corner1.z - ray.origin.z) / ray.direction.z;
            tZmax = (corner2.z - ray.origin.z) / ray.direction.z;
        } else {
            tZmin = (corner2.z - ray.origin.z) / ray.direction.z;
            tZmax = (corner1.z - ray.origin.z) / ray.direction.z;
        }

        double t0, t1;

        // Find the maximum entering value
        t0 = std::max(tXmin, std::min(tYmin, tZmin));
        // Find the minimum exiting value
        t1 = std::min(tXmax, std::max(tYmax, tZmax));

        return t0 < t1 && t1 > EPSILON;
    }

    BoundingBox& BoundingBox::operator=(const BoundingBox& old) {
        corner1 = old.corner1;
        corner2 = old.corner2;

        return *this;
    }
}
