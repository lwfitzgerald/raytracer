#ifndef DISC_H_
#define DISC_H_

#include "Plane.h"

namespace Raytracer {
    class Disc: public Plane {
    public:
        /**
         * Construct a Disc with the given parameters
         */
        Disc(const Point3& position, const Normal& normal, const double& radius)
        :
            Plane(position, normal),
            radius(radius) {}

        /**
         * Copy constructor
         */
        Disc(const Disc &old)
        :
            Plane(old.position, old.normal),
            radius(old.radius) {}

        /**
         * Construct a Disc from an istringstream
         */
        Disc(std::istringstream& iss, const World& world);

        virtual ~Disc() {}

        Disc& operator=(const Disc& rhs);

        virtual bool hit(const Ray& ray, double& tmin) const;

        virtual bool isBoundable() const;
        virtual BoundingBox getBoundingBox() const;
    private:
        double radius;
    };
}

#endif /* DISC_H_ */
