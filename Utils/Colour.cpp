#include "Colour.h"

Colour& Colour::operator=(const Colour& rhs) {
    r = rhs.r;
    g = rhs.g;
    b = rhs.b;

    return *this;
}

Colour Colour::operator+(const Colour& rhs) const {
    return Colour(
        std::max(0.0, std::min(1.0, r + rhs.r)),
        std::max(0.0, std::min(1.0, g + rhs.g)),
        std::max(0.0, std::min(1.0, b + rhs.b))
    );
}

Colour Colour::operator*(const double& rhs) const {
    return Colour(
        std::max(0.0, std::min(1.0, rhs * r)),
        std::max(0.0, std::min(1.0, rhs * g)),
        std::max(0.0, std::min(1.0, rhs * b))
    );
}

Colour Colour::operator/(const double& rhs) const {
    return Colour(
        std::max(0.0, std::min(1.0, r / rhs)),
        std::max(0.0, std::min(1.0, g / rhs)),
        std::max(0.0, std::min(1.0, b / rhs))
    );
}

Colour Colour::operator*(const Colour& rhs) const {
    return Colour(
        std::max(0.0, std::min(1.0, r * rhs.r)),
        std::max(0.0, std::min(1.0, g * rhs.g)),
        std::max(0.0, std::min(1.0, b * rhs.b))
    );
}

Colour Colour::exp(const double& rhs) const {
    return Colour(
        std::max(0.0, std::min(1.0, pow(r, rhs))),
        std::max(0.0, std::min(1.0, pow(g, rhs))),
        std::max(0.0, std::min(1.0, pow(b, rhs)))
    );
}

Colour& Colour::operator+=(const Colour& rhs) {
    r = std::max(0.0, std::min(1.0, r + rhs.r));
    g = std::max(0.0, std::min(1.0, g + rhs.g));
    b = std::max(0.0, std::min(1.0, b + rhs.b));

    return *this;
}
