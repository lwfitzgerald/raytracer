#include "Vector3.h"
#include "Normal.h"

Vector3 Vector3::operator-() const {
    return Vector3(
        -x,
        -y,
        -z
    );
}

Vector3 Vector3::operator+(const Vector3& rhs) const {
    return Vector3(
        x + rhs.x,
        y + rhs.y,
        z + rhs.z
    );
}

Vector3 Vector3::operator-(const Vector3& rhs) const {
    return Vector3(
        x - rhs.x,
        y - rhs.y,
        z - rhs.z
    );
}

Vector3 Vector3::operator-(const Normal& rhs) const {
    return Vector3(
        x - rhs.x,
        y - rhs.y,
        z - rhs.z
    );
}

Vector3& Vector3::operator=(const Vector3& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Vector3 Vector3::operator*(const double& rhs) const {
    return Vector3(
        rhs * x,
        rhs * y,
        rhs * z
    );
}

Vector3 Vector3::operator/(const double& rhs) const {
    return Vector3(
        x / rhs,
        y / rhs,
        z / rhs
    );
}

Vector3& Vector3::operator+=(const Vector3& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;

    return *this;
}

bool Vector3::operator==(const Vector3& rhs) {
    return (std::abs(x - rhs.x) == 0 &&
            std::abs(y - rhs.y) == 0 &&
            std::abs(z - rhs.z) == 0);
}

double Vector3::operator*(const Vector3& rhs) const {
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

double Vector3::operator*(const Normal& rhs) const {
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

double Vector3::mag() const {
    return sqrt(sqr(x) + sqr(y) + sqr(z));
}

double Vector3::magsqr() const {
    return sqr(x) + sqr(y) + sqr(z);
}

Vector3 Vector3::cross(const Vector3& rhs) const {
    return Vector3(
        y * rhs.z - z * rhs.y,
        z * rhs.x - x * rhs.z,
        x * rhs.y - y * rhs.x
    );
}

void Vector3::normalise() {
    double length = mag();

    if (length > 0) {
        x /= length;
        y /= length;
        z /= length;
    }
}

Vector3 Vector3::hat() const {
    Vector3 newVector = *this;
    newVector.normalise();

    return newVector;
}
