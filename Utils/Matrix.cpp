#include "Matrix.h"

namespace Raytracer {
    Matrix::Matrix() {
        // Default to the identity matrix
        setToIdentity();
    }

    Matrix::Matrix(const Matrix& old) {
        for (int i=0; i < 4; i++) {
            for (int j=0; j < 4; j++) {
                matrix[i][j] = old.matrix[i][j];
            }
        }
    }

    Matrix& Matrix::operator=(const Matrix& rhs) {
        for (int i=0; i < 4; i++) {
            for (int j=0; j < 4; j++) {
                matrix[i][j] = rhs.matrix[i][j];
            }
        }

        return *this;
    }

    Matrix Matrix::operator*(const Matrix& rhs) const {
        Matrix result;

        for (int i=0; i < 4; i++) {
            for (int j=0; j < 4; j++) {
                result.matrix[i][j] = 0.0;

                for (int k=0; k < 4; k++) {
                    result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
                }
            }
        }

        return result;
    }

    Matrix Matrix::operator/(const double& rhs) const {
        Matrix result = *this;

        for (int i=0; i < 4; i++) {
            for (int j=0; j < 4; j++) {
                result.matrix[i][j] /= rhs;
            }
        }

        return result;
    }

    Matrix Matrix::transposed() const {
        Matrix result;

        // Assumes square matrix
        for (int i=0; i < 3; i++) {
            for (int j=i+1; j < 4; j++) {
                result.matrix[i][j] = matrix[j][i];
                result.matrix[j][i] = matrix[i][j];
            }
        }

        return result;
    }

    Vector3 Matrix::operator*(const Vector3& rhs) const {
        return Vector3(
            matrix[0][0] * rhs.x + matrix[0][1] * rhs.y + matrix[0][2] * rhs.z,
            matrix[1][0] * rhs.x + matrix[1][1] * rhs.y + matrix[1][2] * rhs.z,
            matrix[2][0] * rhs.x + matrix[2][1] * rhs.y + matrix[2][2] * rhs.z
        );
    }

    void Matrix::setToIdentity() {
        for (int i=0; i < 4; i++) {
            for (int j=0; j < 4; j++) {
                if (i == j) {
                    matrix[i][j] = 1.0;
                } else {
                    matrix[i][j] = 0.0;
                }
            }
        }
    }
}
