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
        std::max(0.0, std::min(1.0, this->r + rhs.r)),
        std::max(0.0, std::min(1.0, this->g + rhs.g)),
        std::max(0.0, std::min(1.0, this->b + rhs.b))
    );
}

Colour Colour::operator*(const double& rhs) const {
    return Colour(
        std::max(0.0, std::min(1.0, rhs * this->r)),
        std::max(0.0, std::min(1.0, rhs * this->g)),
        std::max(0.0, std::min(1.0, rhs * this->b))
    );
}

Colour Colour::operator/(const double& rhs) const {
    return Colour(
        std::max(0.0, std::min(1.0, this->r / rhs)),
        std::max(0.0, std::min(1.0, this->g / rhs)),
        std::max(0.0, std::min(1.0, this->b / rhs))
    );
}

Colour Colour::operator*(const Colour& rhs) const {
    return Colour(
        std::max(0.0, std::min(1.0, this->r * rhs.r)),
        std::max(0.0, std::min(1.0, this->g * rhs.g)),
        std::max(0.0, std::min(1.0, this->b * rhs.b))
    );
}

Colour Colour::exp(const double& rhs) const {
    return Colour(
        std::max(0.0, std::min(1.0, pow(this->r, rhs))),
        std::max(0.0, std::min(1.0, pow(this->g, rhs))),
        std::max(0.0, std::min(1.0, pow(this->b, rhs)))
    );
}

Colour& Colour::operator+=(const Colour& rhs) {
    this->r = std::max(0.0, std::min(1.0, this->r + rhs.r));
    this->g = std::max(0.0, std::min(1.0, this->g + rhs.g));
    this->b = std::max(0.0, std::min(1.0, this->b + rhs.b));

    return *this;
}
