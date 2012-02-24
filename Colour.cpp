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
