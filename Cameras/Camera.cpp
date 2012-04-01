#include "Camera.h"

#include "../Utils/Matrix.h"

namespace Raytracer {
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
        this->rollAngle = angle * (PI / 180);

        this->up = getRollTransform() * this->up;
    }

    void Camera::calcUVW() {
        // First check for singularities...

        // Check if camera is looking vertically down
        if (this->eye == this->lookAt && this->eye.y > this->lookAt.y) {
            this->u = Vector3(0.0, 0.0, 1.0);
            this->v = Vector3(1.0, 0.0, 0.0);
            this->w = Vector3(0.0, 1.0, 0.0);

            return;
        }

        // Check if camera is looking vertically up
        if (this->eye == this->lookAt && this->eye.y < this->lookAt.y) {
            this->u = Vector3(1.0, 0.0, 0.0);
            this->v = Vector3(0.0, 0.0, 1.0);
            this->w = Vector3(0.0, -1.0, 0.0);

            return;
        }

        this->w = this->eye - this->lookAt;
        this->w.normalise();
        this->u = this->up.cross(this->w);
        this->u.normalise();
        this->v = this->w.cross(this->u);
    }

    Matrix Camera::getRollTransform() const {
        Matrix T1;
        T1.matrix[0][3] = this->eye.x - this->lookAt.x;
        T1.matrix[1][3] = this->eye.y - this->lookAt.y;
        T1.matrix[2][3] = this->eye.z - this->lookAt.z;

        Matrix R;
        R.matrix[0][0] = this->u.x;
        R.matrix[0][1] = this->u.y;
        R.matrix[0][2] = this->u.z;
        R.matrix[1][0] = this->v.x;
        R.matrix[1][1] = this->v.y;
        R.matrix[1][2] = this->v.z;
        R.matrix[2][0] = this->w.x;
        R.matrix[2][1] = this->w.y;
        R.matrix[2][2] = this->w.z;

        Matrix RT = R.transposed();

        Matrix RzNegAlpha;
        RzNegAlpha.matrix[0][0] = cos(this->rollAngle);
        RzNegAlpha.matrix[0][1] = sin(this->rollAngle);
        RzNegAlpha.matrix[1][0] = -sin(this->rollAngle);
        RzNegAlpha.matrix[1][1] = cos(this->rollAngle);

        Matrix T2;
        T2.matrix[0][3] = -(this->eye.x - this->lookAt.x);
        T2.matrix[1][3] = -(this->eye.y - this->lookAt.y);
        T2.matrix[2][3] = -(this->eye.z - this->lookAt.z);

        return T1 * RT * RzNegAlpha * R * T2;
    }
}
