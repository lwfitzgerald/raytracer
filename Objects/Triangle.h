#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Plane.h"

class Triangle: public Plane {
public:
    Triangle() {}

    Triangle(const Point3& A, const Point3& B, const Point3& C);

    Triangle(const Triangle& old);

    virtual ~Triangle() {}

    Triangle& operator=(const Triangle& rhs);

    virtual bool hit(const Ray& ray, double& tmin) const;

private:
    // Vertices
    Point3 A;
    Point3 B;
    Point3 C;

    // Store a copy of the projected vertices
    Point3 projectedA;
    Point3 projectedB;
    Point3 projectedC;

    enum Axis {X_AXIS, Y_AXIS, Z_AXIS};

    /**
     * Calculate and set:
     * Position
     * Normal
     * Projected vertices
     */
    void prepare();

    Axis identifyDominantAxis() const;
};

#endif /* TRIANGLE_H_ */