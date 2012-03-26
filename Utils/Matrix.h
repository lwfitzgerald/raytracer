#ifndef MATRIX_H_
#define MATRIX_H_

#include "../Prereqs.h"
#include "Vector3.h"

class Matrix {
public:
    double matrix[4][4]; // We won't need a matrix bigger than 4x4

    Matrix();

    Matrix(const Matrix& old);

    ~Matrix() {}

    Matrix& operator=(const Matrix& rhs);

    Matrix operator*(const Matrix& rhs) const;
    Matrix operator/(const double& rhs) const;

    Matrix transposed() const;

    Vector3 operator*(const Vector3& rhs) const;

    __inline friend std::ostream& operator<<(std::ostream &lhs, Matrix& rhs) {
        for (int i=0; i < 4; i++) {
            for (int j=0; j < 4; j++) {
                lhs << rhs.matrix[i][j] << " ";
            }
            lhs << std::endl;
        }

        return lhs;
    }

    void setToIdentity();
};

#endif /* MATRIX_H_ */
