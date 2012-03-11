/*
 * Colour.cpp
 *
 *  Created on: 24 Feb 2012
 *      Author: darkip
 */

#include "Colour.h"

Colour& Colour::operator=(const Colour& rhs) {
    this->r = rhs.r;
    this->g = rhs.g;
    this->b = rhs.b;

    return *this;
}

Colour Colour::operator+(const Colour& rhs) const {
    return Colour(
        this->r + rhs.r,
        this->g + rhs.g,
        this->b + rhs.b
    );
}

Colour Colour::operator*(const double& rhs) const {
    return Colour(
        rhs * this->r,
        rhs * this->g,
        rhs * this->b
    );
}

Colour Colour::operator/(const double& rhs) const {
    return Colour(
        this->r / rhs,
        this->g / rhs,
        this->b / rhs
    );
}

Colour Colour::operator*(const Colour& rhs) const {
    return Colour(
        this->r * rhs.r,
        this->g * rhs.g,
        this->b * rhs.b
    );
}

Colour Colour::exp(const double& rhs) const {
    return Colour(
        pow(this->r, rhs),
        pow(this->g, rhs),
        pow(this->b, rhs)
    );
}

Colour& Colour::operator+=(const Colour& rhs) {
    this->r += rhs.r;
    this->g += rhs.g;
    this->b += rhs.b;

    return *this;
}