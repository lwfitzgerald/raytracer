#include "Colour.h"

namespace Raytracer {
    Colour& Colour::operator=(const Colour& rhs) {
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;

        return *this;
    }

    Colour Colour::operator+(const Colour& rhs) const {
        return Colour(
            r + rhs.r,
            g + rhs.g,
            b + rhs.b
        );
    }

    Colour Colour::operator*(const double& rhs) const {
        return Colour(
            rhs * r,
            rhs * g,
            rhs * b
        );
    }

    Colour Colour::operator/(const double& rhs) const {
        return Colour(
            r / rhs,
            g / rhs,
            b / rhs
        );
    }

    Colour Colour::operator*(const Colour& rhs) const {
        return Colour(
            r * rhs.r,
            g * rhs.g,
            b * rhs.b
        );
    }

    Colour Colour::exp(const double& rhs) const {
        return Colour(
            pow(r, rhs),
            pow(g, rhs),
            pow(b, rhs)
        );
    }

    Colour& Colour::operator+=(const Colour& rhs) {
        r = r + rhs.r;
        g = g + rhs.g;
        b = b + rhs.b;

        return *this;
    }

    Colour& Colour::toneClamp() {
        double max = std::max(r, std::max(g, b));

        if (max > 1) {
            r = r / max;
            g = g / max;
            b = b / max;
        }

        return *this;
    }
}
