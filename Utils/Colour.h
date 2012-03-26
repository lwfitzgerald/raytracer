#ifndef COLOUR_H_
#define COLOUR_H_

#include "../Prereqs.h"

class Colour {
public:
    double r;
    double g;
    double b;

    Colour()
    :
        r(0),
        g(0),
        b(0) {}

    Colour(const double r, const double g, const double b)
    :
        r(std::max(0.0, std::min(1.0, r))),
        g(std::max(0.0, std::min(1.0, g))),
        b(std::max(0.0, std::min(1.0, b))) {}

    Colour(const Colour& old)
    :
        r(std::max(0.0, std::min(1.0, old.r))),
        g(std::max(0.0, std::min(1.0, old.g))),
        b(std::max(0.0, std::min(1.0, old.b))) {}

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
