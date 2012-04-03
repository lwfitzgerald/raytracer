#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Plane.h"

namespace Raytracer {
    class Triangle: public Plane {
    public:
        /**
         * Construct a Triangle with the given parameters
         */
        Triangle(const Point3& A, const Point3& B, const Point3& C);

        /**
         * Copy constructor
         */
        Triangle(const Triangle& old);

        /**
         * Construct a Triangle from an istringstream
         */
        Triangle(std::istringstream& iss, World& world);

        virtual ~Triangle() {}

        Triangle& operator=(const Triangle& rhs);

        virtual bool hit(const Ray& ray, double& tmin) const;
        virtual bool isBoundable() const;
        virtual BoundingBox getBoundingBox() const;

    private:
        // Vertices
        Point3 A;
        Point3 B;
        Point3 C;

        // Store a copy of the projected vertices
        Point3 projectedA;
        Point3 projectedB;
        Point3 projectedC;

        /**
         * Calculate and set:
         * Position
         * Normal
         * Projected vertices
         */
        void prepare();

        /**
         * Identify the dominant axis of the vertices
         */
        Axis identifyDominantAxis() const;
    };
}

#endif /* TRIANGLE_H_ */
