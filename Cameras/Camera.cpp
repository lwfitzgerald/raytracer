#include "Camera.h"

#include "../Utils/Matrix.h"

namespace Raytracer {
    Camera::Camera(std::istringstream& iss)
    :
        rollAngle(0.0),
        up(0.0, 1.0, 0.0),
        u(1.0, 0.0, 0.0),
        v(0.0, 1.0, 0.0),
        w(0.0, 0.0, 1.0) {

        double eyeX, eyeY, eyeZ;

        iss >> eyeX;
        iss >> eyeY;
        iss >> eyeZ;

        double lookAtX, lookAtY, lookAtZ;

        iss >> lookAtX;
        iss >> lookAtY;
        iss >> lookAtZ;

        double rollAngle;

        iss >> rollAngle;

        eye = Point3(eyeX, eyeY, eyeZ);
        lookAt = Point3(lookAtX, lookAtY, lookAtZ);
        calcUVW();

        if (rollAngle != 0) {
            setRollAngle(rollAngle);
            calcUVW();
        }
    }

    void Camera::setEyePoint(const Point3& point) {
        this->eye = point;
    }

    void Camera::setLookAtPoint(const Point3& point) {
        this->lookAt = point;
    }

    void Camera::setUpVector(const Vector3& vector) {
        this->up = vector;
    }

    void Camera::setRollAngle(const double& angle) {
        // Then do the new roll
        rollAngle = angle * (PI / 180);

        up = getRollTransform() * up;
    }

    void Camera::calcUVW() {
        // First check for singularities...

        // Check if camera is looking vertically down
        if (eye == lookAt && eye.y > lookAt.y) {
            u = Vector3(0.0, 0.0, 1.0);
            v = Vector3(1.0, 0.0, 0.0);
            w = Vector3(0.0, 1.0, 0.0);

            return;
        }

        // Check if camera is looking vertically up
        if (eye == lookAt && eye.y < lookAt.y) {
            u = Vector3(1.0, 0.0, 0.0);
            v = Vector3(0.0, 0.0, 1.0);
            w = Vector3(0.0, -1.0, 0.0);

            return;
        }

        w = eye - lookAt;
        w.normalise();
        u = up.cross(w);
        u.normalise();
        v = w.cross(u);
    }

    Matrix Camera::getRollTransform() const {
        Matrix T1;
        T1.matrix[0][3] = eye.x - lookAt.x;
        T1.matrix[1][3] = eye.y - lookAt.y;
        T1.matrix[2][3] = eye.z - lookAt.z;

        Matrix R;
        R.matrix[0][0] = u.x;
        R.matrix[0][1] = u.y;
        R.matrix[0][2] = u.z;
        R.matrix[1][0] = v.x;
        R.matrix[1][1] = v.y;
        R.matrix[1][2] = v.z;
        R.matrix[2][0] = w.x;
        R.matrix[2][1] = w.y;
        R.matrix[2][2] = w.z;

        Matrix RT = R.transposed();

        Matrix RzNegAlpha;
        RzNegAlpha.matrix[0][0] = cos(rollAngle);
        RzNegAlpha.matrix[0][1] = sin(rollAngle);
        RzNegAlpha.matrix[1][0] = -sin(rollAngle);
        RzNegAlpha.matrix[1][1] = cos(rollAngle);

        Matrix T2;
        T2.matrix[0][3] = -(eye.x - lookAt.x);
        T2.matrix[1][3] = -(eye.y - lookAt.y);
        T2.matrix[2][3] = -(eye.z - lookAt.z);

        return T1 * RT * RzNegAlpha * R * T2;
    }
}
