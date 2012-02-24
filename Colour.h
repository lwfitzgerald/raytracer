/*
 * Colour.h
 *
 *  Created on: 24 Feb 2012
 *      Author: darkip
 */

#ifndef COLOUR_H_
#define COLOUR_H_

class Colour {
public:
    int r;
    int g;
    int b;

    Colour() {}

    Colour(int r, int g, int b)
    : r(r), g(g), b(b) {}

    Colour(Colour& old)
    : r(old.r), g(old.g), b(old.b) {}

    ~Colour();

    Colour& operator=(const Colour& rhs);
};

#endif /* COLOUR_H_ */
