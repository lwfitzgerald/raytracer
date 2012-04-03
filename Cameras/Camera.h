#ifndef CAMERA_H_
#define CAMERA_H_

#include "../Prereqs.h"

#include "../Utils/Point3.h"
#include "../Utils/Vector3.h"

namespace Raytracer {
    class Camera {
    public:
        Camera()
        :
            eye(0.0, 0, 350.0),
            lookAt(0.0, 0.0, 0.0),
            rollAngle(0.0),
            up(0.0, 1.0, 0.0),
            u(1.0, 0.0, 0.0),
            v(0.0, 1.0, 0.0),
            w(0.0, 0.0, 1.0) {}

        virtual ~Camera() {}

        /**
         * Render the pixel with array coordinates.
         *
         * Where array coordinates are:
         * 0 -> resX, 0->resY
         */
        virtual void renderPixel(const unsigned int arrayX, const unsigned int arrayY,
                    World& world) const = 0;

        /**
         * Set the eye point of the camera
         */
        void setEyePoint(const Point3& point);

        /**
         * Set the look at point of the camera
         */
        void setLookAtPoint(const Point3& point);

        /**
         * Set the up vector of the camera
         */
        void setUpVector(const Vector3& vector);

        /**
         * Set the roll angle of the camera
         */
        void setRollAngle(const double& angle);

        /*
         * Calculate u,v,w of the orthonormal basis
         */
        void calcUVW();

    protected:
        Point3 eye;
        Point3 lookAt;
        double rollAngle;
        Vector3 up;
        Vector3 u;
        Vector3 v;
        Vector3 w;

        /**
         * Get the matrix transform to roll the up vector
         */
        Matrix getRollTransform() const;
    };
}

#endif /* CAMERA_H_ */
