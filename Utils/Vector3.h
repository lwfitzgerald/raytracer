#ifndef VECTOR3_H_
#define VECTOR3_H_

#include "../Prereqs.h"

class Vector3 {
public:
    double x;
    double y;
    double z;

    Vector3() {};

    Vector3(const double x, const double y, const double z)
    : x(x), y(y), z(z) {}

    Vector3(const Vector3& old)
    : x(old.x), y(old.y), z(old.z) {}

    ~Vector3() {};

    Vector3 operator-() const;

    Vector3 operator+(const Vector3& rhs) const;
    Vector3 operator-(const Vector3& rhs) const;
    Vector3 operator-(const Normal& rhs) const;
    Vector3& operator=(const Vector3& rhs);

    // Scalar mult
    friend Vector3 operator*(const double& lhs, const Vector3& rhs) {
        return rhs * lhs;
    }
    Vector3 operator*(const double& rhs) const;

    Vector3 operator/(const double& rhs) const;

    Vector3& operator+=(const Vector3& rhs);
    Vector3& operator-=(const Vector3& rhs);

    bool operator==(const Vector3& rhs);

    // Dot product
    double operator*(const Vector3& rhs) const;
    double operator*(const Normal& rhs) const;

    double mag() const;
    double magsqr() const;

    Vector3 cross(const Vector3& other) const;

    void normalise();
    Vector3 hat() const;

    __inline friend std::ostream& operator<<(std::ostream& lhs, Vector3& rhs) {
        lhs << "(" << rhs.x << "," << rhs.y << "," << rhs.z << ")";

        return lhs;
    }
};

#endif /* VECTOR3_H_ */
