#ifndef VIEWPLANE_H_
#define VIEWPLANE_H_

#include "Prereqs.h"

#include "Utils/Colour.h"

class ViewPlane {
public:
    int horizontalRes;
    int verticalRes;
    float pixelSize;

    // Initialise pixelColours to NULL in constructor
    ViewPlane()
    : pixelColours(NULL) {}

    ~ViewPlane() {
        // Free pixel colour array if necessary
        if (pixelColours != NULL) {
            delete[] pixelColours;
        }
    }

    void setResolution(const int horizontal, const int vertical);
    void setPixelSize(const float pixelSize);

    void setPixelColour(const int x, const int y, const Colour& colour);
    Colour& getPixelColour(const int x, const int y) const;

    void writePPM(const char* filename) const;

private:
    Colour* pixelColours;
};

#endif /* VIEWPLANE_H_ */
