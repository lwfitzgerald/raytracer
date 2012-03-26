#include "Triangle.h"
#include "../Utils/Ray.h"

Triangle::Triangle(const Point3& A, const Point3& B, const Point3& C)
: A(A), B(B), C(C) {
    prepare();
}

Triangle::Triangle(const Triangle& old)
:
    A(old.A),
    B(old.B),
    C(old.C) {
    prepare();
}

Triangle& Triangle::operator=(const Triangle& rhs) {
    Plane::operator=(rhs);

    A = rhs.A;
    B = rhs.B;
    C = rhs.C;

    prepare();

    return *this;
}

bool Triangle::hit(const Ray& ray, double& tmin) const {
    double planarT = tmin;

    if (Plane::hit(ray, planarT)) {
        Point3 poi = ray.origin + planarT * ray.direction;

        Axis dominantAxis = identifyDominantAxis();

        if (dominantAxis == X_AXIS) {
            poi.x = 0;
        } else if (dominantAxis == Y_AXIS) {
            poi.y = 0;
        } else {
            poi.z = 0;
        }

        /*
         * Calculate cross products
         *
         * Point lies on triangle if direction of all three
         * vectors is the same
         */
        Vector3 pMinusAxBMinusA = (poi - projectedA).cross(projectedB - projectedA).hat();
        Vector3 pMinusBxCMinusB = (poi - projectedB).cross(projectedC - projectedB).hat();
        Vector3 pMinusCxAMinusC = (poi - projectedC).cross(projectedA - projectedC).hat();

        if (pMinusAxBMinusA == pMinusBxCMinusB
            && pMinusBxCMinusB == pMinusCxAMinusC) {
            tmin = planarT;
            return true;
        }
    }

    return false;
}

void Triangle::prepare() {
    position = A;
    normal = (C - A).cross(B - A).hat();

    // Store the projected vertices

    Axis dominantAxis = identifyDominantAxis();

    if (dominantAxis == X_AXIS) {
        projectedA = Point3(0, A.y, A.z);
        projectedB = Point3(0, B.y, B.z);
        projectedC = Point3(0, C.y, C.z);
    } else if (dominantAxis == Y_AXIS) {
        projectedA = Point3(A.x, 0, A.z);
        projectedB = Point3(B.x, 0, B.z);
        projectedC = Point3(C.x, 0, C.z);
    } else {
        projectedA = Point3(A.x, A.y, 0);
        projectedB = Point3(B.x, B.y, 0);
        projectedC = Point3(C.x, C.y, 0);
    }
}

Triangle::Axis Triangle::identifyDominantAxis() const {
    Axis axis = X_AXIS;
    double max = std::abs(normal.x);

    if (std::abs(normal.y) > max) {
        max = std::abs(normal.y);
        axis = Y_AXIS;
    }

    if (std::abs(normal.z) > max) {
        max = std::abs(normal.z);
        axis = Z_AXIS;
    }

    return axis;
}