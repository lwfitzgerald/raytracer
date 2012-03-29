#ifndef SPHERE_H_
#define SPHERE_H_

#include "Object.h"
#include "../Utils/Point3.h"

class Sphere: public Object {
public:
    Sphere(const Point3& center, const double& radius)
    : center(center), radius(radius) {}

    Sphere(const Sphere& old)
    : center(old.center), radius(old.radius) {}

    Sphere(std::istringstream& iss, World& world);

    virtual ~Sphere() {}

    Sphere& operator=(Sphere& rhs);

    virtual bool hit(const Ray& ray, double& tmin) const;
    virtual void getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const;

    virtual bool isBoundable() const;

    virtual BoundingBox getBoundingBox() const;

private:
    Point3 center;
    double radius;
};

#endif /* SPHERE_H_ */
