#ifndef DISC_H_
#define DISC_H_

#include "Plane.h"

class Disc: public Plane {
public:
    Disc(const Point3& position, const Normal& normal, const double& radius)
    :
        Plane(position, normal),
        radius(radius) {}

    Disc(const Disc &old)
    :
        Plane(old.position, old.normal),
        radius(old.radius) {}

    virtual ~Disc() {}

    Disc& operator=(const Disc& rhs);

    virtual bool hit(const Ray& ray, double& tmin) const;

private:
    double radius;
};

#endif /* DISC_H_ */
