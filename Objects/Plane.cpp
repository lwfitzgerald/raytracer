#include "Plane.h"
#include "../Utils/Ray.h"
#include "../Utils/ShadeInfo.h"

namespace Raytracer {
    Plane::Plane(std::istringstream& iss, const World& world) {
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
        double ND = normal * ray.direction;

        if (ND == 0) {
            return false;
        }

        double t = (position - ray.origin) * normal / ND;

        if (t > EPSILON && t < tmin) {
            tmin = t;
            return true;
        }

        return false;
    }

    void Plane::getShadeInfo(ShadeInfo& shadeInfo, const Ray& ray, const double& tmin) const {
        shadeInfo.hitNormal = normal;

        // Flip normal in case of other side intersection
        if (shadeInfo.hitNormal * -ray.direction < 0) {
            shadeInfo.hitNormal = -shadeInfo.hitNormal;
            shadeInfo.normalFlipped = true;
        }

        shadeInfo.hitPoint = ray.origin + tmin * ray.direction;
    }

    bool Plane::isBoundable() const {
        return false;
    }

    BoundingBox Plane::getBoundingBox() const {
        // Not called but implemented for completeness

        Point3 corner1, corner2;

        if (normal.x == 0 && normal.y == 0) {
            corner1.x = -std::numeric_limits<double>::infinity();
            corner1.y = -std::numeric_limits<double>::infinity();
            corner1.z = position.z;

            corner2.x = std::numeric_limits<double>::infinity();
            corner2.y = std::numeric_limits<double>::infinity();
            corner2.z = position.z;
        } else if (normal.x == 0 && normal.z == 0) {
            corner1.x = -std::numeric_limits<double>::infinity();
            corner1.y = position.y;
            corner1.z = -std::numeric_limits<double>::infinity();

            corner2.x = std::numeric_limits<double>::infinity();
            corner2.y = position.y;
            corner2.z = std::numeric_limits<double>::infinity();
        } else if (normal.y == 0 && normal.z == 0) {
            corner1.x = position.x;
            corner1.y = -std::numeric_limits<double>::infinity();
            corner1.z = -std::numeric_limits<double>::infinity();

            corner2.x = position.x;
            corner2.y = std::numeric_limits<double>::infinity();
            corner2.z = std::numeric_limits<double>::infinity();
        } else {
            corner1.x = -std::numeric_limits<double>::infinity();
            corner1.y = -std::numeric_limits<double>::infinity();
            corner1.z = -std::numeric_limits<double>::infinity();

            corner2.x = std::numeric_limits<double>::infinity();
            corner2.y = std::numeric_limits<double>::infinity();
            corner2.z = std::numeric_limits<double>::infinity();
        }

        return BoundingBox(
            corner1,
            corner2
        );
    }

    bool Plane::hasVolume() const {
        // A plane is infinitely thin
        return false;
    }
}
