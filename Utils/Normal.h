#ifndef NORMAL_H_
#define NORMAL_H_

#include "../Prereqs.h"

namespace Raytracer {
    class Normal {
    public:
        double x;
        double y;
        double z;

        Normal() {}

        /**
         * Construct a Normal with the given parameters
         */
        Normal(const double x, const double y, const double z)
        : x(x), y(y), z(z) {}

        /**
         * Copy constructor
         */
        Normal(const Normal& old)
        : x(old.x), y(old.y), z(old.z) {}

        ~Normal() {}

        Normal operator-() const;

        Normal operator+(const Normal& rhs) const;
        Vector3 operator+(const Vector3& rhs) const;

        /**
         * Method to allow double * Normal operations using
         * the Normal * double method
         */
        friend Normal operator*(const double& lhs, const Normal& rhs) {
            return rhs * lhs;
        }
        Normal operator*(const double& rhs) const;

        double operator*(const Vector3& rhs) const;

        Normal& operator=(const Normal& rhs);
        Normal& operator=(const Vector3& rhs);
        Normal& operator=(const Point3& rhs);

        Normal& operator+=(const Normal& rhs);
        Normal& operator-=(const Normal& rhs);
    };
}

#endif /* NORMAL_H_ */
