#ifndef VIEWPLANE_H_
#define VIEWPLANE_H_

#include "Prereqs.h"

#include "Utils/Colour.h"

namespace Raytracer {
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

        /**
         * Set the resolution of the view plane
         */
        void setResolution(const int horizontal, const int vertical);

        /**
         * Set the pixel size of the view plane
         */
        void setPixelSize(const float pixelSize);

        /**
         * Set the colour of a pixel in the framebuffer
         */
        void setPixelColour(const int x, const int y, const Colour& colour);

        /**
         * Get the colour of the pixel at the given
         * coordinates in the framebuffer
         */
        Colour& getPixelColour(const int x, const int y) const;

        /**
         * Write the framebuffer to file
         */
        void writePPM(const char* filename) const;

    private:
        Colour* pixelColours;
    };
}

#endif /* VIEWPLANE_H_ */
