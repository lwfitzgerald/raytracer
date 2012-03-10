/*
 * Colour.h
 *
 *  Created on: 24 Feb 2012
 *      Author: darkip
 */

#ifndef COLOUR_H_
#define COLOUR_H_

#include "../Prereqs.h"

class Colour {
public:
    double r;
    double g;
    double b;

    Colour() {}

    Colour(const double r, const double g, const double b)
    : r(r), g(g), b(b) {}

    Colour(const Colour& old)
    : r(old.r), g(old.g), b(old.b) {}

    ~Colour() {}

    Colour& operator=(const Colour& rhs);

    Colour operator+(const Colour& rhs) const;

    __inline friend Colour operator*(const double& lhs, const Colour& rhs) {
        return rhs * lhs;
    }
    Colour operator*(const double& rhs) const;

    Colour operator/(const double& rhs) const;
    Colour operator*(const Colour& rhs) const;

    Colour exp(const double& rhs) const;

    Colour& operator+=(const Colour& rhs);
};

#endif /* COLOUR_H_ */
