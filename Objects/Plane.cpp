#include "Plane.h"
#include "../Utils/Ray.h"
#include "../Utils/ShadeInfo.h"

Plane::Plane(std::istringstream& iss, World& world) {
    // Construct apart from the material
    constructMinusMaterial(iss);

    // Store the material
    fetchMaterial(iss, world);
}

void Plane::constructMinusMaterial(std::istringstream& iss) {
    // Extract the position

    double x, y, z;

    iss >> x;
    iss >> y;
    iss >> z;

    // Extract the normal vector

    double normalX, normalY, normalZ;

    iss >> normalX;
    iss >> normalY;
    iss >> normalZ;

    // Create and set the position and normal
    position = Point3(x, y, z);
    normal = Normal(normalX, normalY, normalZ);
}

Plane& Plane::operator=(const Plane& rhs) {
    this->position = rhs.position;
    this->normal = rhs.normal;

    return *this;
}

bool Plane::hit(const Ray& ray, double& tmin) const {
    double t = (position - ray.origin) * normal / (ray.direction * normal);

    if (t > epsilon) {
        tmin = t;
        return true;
    }

    return false;
}

void Plane::getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const {
    shadeInfo.hitNormal = normal;
    shadeInfo.hitPoint = ray.origin + tmin * ray.direction;
}
