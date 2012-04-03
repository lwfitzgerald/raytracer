#ifndef POINT_H_
#define POINT_H_

#include "../Prereqs.h"

#include "Vector3.h"

namespace Raytracer {
    class Point3 {
    public:
        double x;
        double y;
        double z;

        Point3() {}

        /**
         * Construct a Point3 with the given parameters
         */
        Point3(const double x, const double y, const double z)
        : x(x), y(y), z(z) {}

        /**
         * Copy constructor
         */
        Point3(const Point3& old)
        : x(old.x), y(old.y), z(old.z) {}

        ~Point3() {}

        Point3 operator+(const Vector3& other) const;
        Point3 operator-(const Vector3& rhs) const;

        Vector3 operator-(const Point3& rhs) const;

        Point3& operator=(const Point3& rhs);

        /**
         * Method to allow double * Point3 operations using
         * the Point3 * double method
         */
        friend Point3 operator*(const double& lhs, const Point3& rhs) {
            return rhs * lhs;
        }
        Point3 operator*(const double& rhs) const;

        Point3& operator+=(const Vector3& rhs);
        Point3& operator-=(const Vector3& rhs);

        bool operator==(const Point3& rhs);
    };
}

#endif /* POINT_H_ */
