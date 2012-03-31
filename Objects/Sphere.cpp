#include "Sphere.h"
#include "../Utils/Ray.h"
#include "../Utils/Vector3.h"
#include "../Utils/ShadeInfo.h"

Sphere::Sphere(std::istringstream& iss, World& world) {
    // Extract center

    double x, y, z;

    iss >> x;
    iss >> y;
    iss >> z;

    // Extract and store radius
    iss >> radius;

    // Store the material
    fetchMaterial(iss, world);

    // Create and store center
    center = Point3(x, y, z);
}

Sphere& Sphere::operator=(Sphere& rhs) {
    this->center = rhs.center;
    this->radius = rhs.radius;

    return *this;
}

bool Sphere::hit(const Ray& ray, double& tmin) const {
    Vector3 oMinusC = ray.origin - center;
    const double a = ray.direction * ray.direction;
    const double b = 2.0 * ray.direction * oMinusC;
    const double c = oMinusC * oMinusC - sqr(radius);
    const double disc = sqr(b) - 4.0 * a * c;

    if (disc < 0) {
        // No hits
        return false;
    }

    const double discroot = sqrt(disc);
    const double denom = 2.0 * a;

    // Handle the - root
    double t = (-b - discroot) / denom;

    if (t > epsilon) {
        tmin = t;
        return true;
    }

    // Handle the + root
    t = (-b + discroot) / denom;

    if (t > epsilon && t) {
        tmin = t;
        return true;
    }

    return false;
}

void Sphere::getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const {
    Vector3 oMinusC = ray.origin - center;

    // Normal calculated by vector from C to P and then normalised using the radius
    shadeInfo.hitNormal = (oMinusC + tmin * ray.direction) / radius;
    shadeInfo.hitPoint = ray.origin + tmin * ray.direction;
}
