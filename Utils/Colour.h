#ifndef COLOUR_H_
#define COLOUR_H_

#include "../Prereqs.h"

namespace Raytracer {
    class Colour {
    public:
        double r;
        double g;
        double b;

        /**
         * Default constructor, initialises to Black
         */
        Colour()
        : r(0), g(0), b(0) {}

        /**
         * Create a Colour with the given RGB values
         */
        Colour(const double r, const double g, const double b)
        : r(r),g(g), b(b) {}

        /**
         * Copy constructor
         */
        Colour(const Colour& old)
        : r(old.r), g(old.g), b(old.b) {}

        ~Colour() {}

        Colour& operator=(const Colour& rhs);

        Colour operator+(const Colour& rhs) const;

        /**
         * Inline method to allow double * Colour
         * using the Colour * double method
         */
        __inline friend Colour operator*(const double& lhs, const Colour& rhs) {
            return rhs * lhs;
        }
        Colour operator*(const double& rhs) const;

        Colour operator/(const double& rhs) const;
        Colour operator*(const Colour& rhs) const;

        Colour exp(const double& rhs) const;

        Colour& operator+=(const Colour& rhs);

        /**
         * Clamp values between 0 and 1 whilst maintaining tone
         */
        Colour& toneClamp();
    };
}

#endif /* COLOUR_H_ */
