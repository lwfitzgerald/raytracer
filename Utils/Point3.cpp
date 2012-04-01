#include "Point3.h"

namespace Raytracer {
    Point3 Point3::operator+(const Vector3& other) const {
        return Point3(
            x + other.x,
            y + other.y,
            z + other.z
        );
    }

    Point3 Point3::operator-(const Vector3& rhs) const {
        return Point3(
            x - rhs.x,
            y - rhs.y,
            z - rhs.z
        );
    }

    Vector3 Point3::operator-(const Point3& rhs) const {
        return Vector3(
            x - rhs.x,
            y - rhs.y,
            z - rhs.z
        );
    }

    Point3& Point3::operator=(const Point3& rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;

        return *this;
    }

    Point3 Point3::operator*(const double& rhs) const {
        return Point3(
            rhs * x,
            rhs * y,
            rhs * z
        );
    }

    Point3& Point3::operator+=(const Vector3& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;

        return *this;
    }

    Point3& Point3::operator-=(const Vector3& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;

        return *this;
    }

    bool Point3::operator==(const Point3& rhs) {
        return x == rhs.x &&
               y == rhs.y &&
               z == rhs.z;
    }
}
