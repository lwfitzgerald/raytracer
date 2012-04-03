#ifndef VECTOR3_H_
#define VECTOR3_H_

#include "../Prereqs.h"

namespace Raytracer {
    class Vector3 {
    public:
        double x;
        double y;
        double z;

        Vector3() {};

        /**
         * Construct a Vector3 with the given parameters
         */
        Vector3(const double x, const double y, const double z)
        : x(x), y(y), z(z) {}

        /**
         * Copy constructor
         */
        Vector3(const Vector3& old)
        : x(old.x), y(old.y), z(old.z) {}

        ~Vector3() {};

        Vector3 operator-() const;

        Vector3 operator+(const Vector3& rhs) const;
        Vector3 operator-(const Vector3& rhs) const;
        Vector3 operator-(const Normal& rhs) const;
        Vector3& operator=(const Vector3& rhs);

        /**
         * Allow double * Vector3 operations using the
         * Vector3 * double method
         */
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

        /**
         * Get the magnitude of this vector
         */
        double mag() const;

        /**
         * Get the squared magnitude of this vector
         * (sMore efficient than mag() )
         */
        double magsqr() const;

        /**
         * Get the cross product of this vector and another
         */
        Vector3 cross(const Vector3& other) const;

        /**
         * Normalise the vector
         */
        void normalise();

        /**
         * Return a normalised copy of this vector
         */
        Vector3 hat() const;

        /**
         * Allow output of a Vector3 on a stream
         */
        __inline friend std::ostream& operator<<(std::ostream& lhs, Vector3& rhs) {
            lhs << "(" << rhs.x << "," << rhs.y << "," << rhs.z << ")";

            return lhs;
        }
    };
}

#endif /* VECTOR3_H_ */
