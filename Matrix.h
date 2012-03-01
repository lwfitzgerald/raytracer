/*
 * Matrix.h
 *
 *  Created on: 29 Feb 2012
 *      Author: darkip
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Prereqs.h"
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

    void setToIdentity();
};

#endif /* MATRIX_H_ */
