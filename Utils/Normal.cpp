#include "Normal.h"
#include "Vector3.h"
#include "Point3.h"

namespace Raytracer {
    Normal Normal::operator-() const {
        return Normal(
            -x,
            -y,
            -z
        );
    }

    Normal Normal::operator+(const Normal& rhs) const {
        return Normal(
            x + rhs.x,
            y + rhs.y,
            z + rhs.z
        );
    }

    Vector3 Normal::operator+(const Vector3& rhs) const {
        return Vector3(
            x + rhs.x,
            y + rhs.y,
            z + rhs.z
        );
    }

    Normal Normal::operator*(const double& rhs) const {
        return Normal(
            rhs * x,
            rhs * y,
            rhs * z
        );
    }

    double Normal::operator*(const Vector3& rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    Normal& Normal::operator=(const Normal& rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;

        return *this;
    }

    Normal& Normal::operator=(const Vector3& rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;

        return *this;
    }

    Normal& Normal::operator=(const Point3& rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;

        return *this;
    }

    Normal& Normal::operator+=(const Normal& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;

        return *this;
    }

    Normal& Normal::operator-=(const Normal& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;

        return *this;
    }
}
