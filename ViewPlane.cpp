#include "ViewPlane.h"

#define PPM_MAGIC_NUMBER       "P3" // PPM magic number
#define PPM_MAX_CHARS_PER_LINE 70   // Maximum number of characters per line
#define MAX_COLOUR_VALUE       255  // Maximum colour value
#define MAX_COLOUR_VALUE_CHARS 3    // Maximum number of characters for a colour value

namespace Raytracer {
    void ViewPlane::setResolution(const int horizontal, const int vertical) {
        this->horizontalRes = horizontal;
        this->verticalRes = vertical;

        // Free any pre-existing array
        if (pixelColours != NULL) {
            delete[] pixelColours;
        }

        pixelColours = new Colour[this->horizontalRes * this->verticalRes];
    }

    void ViewPlane::setPixelSize(const float pixelSize) {
        this->pixelSize = pixelSize;
    }

    void ViewPlane::setPixelColour(const int x, const int y, const Colour& colour) {
        pixelColours[y * this->horizontalRes + x] = colour;
    }

    Colour& ViewPlane::getPixelColour(const int x, const int y) const {
        return pixelColours[y * this->horizontalRes + x];
    }

    void ViewPlane::writePPM(const char* filename) const {
        std::ofstream file;
        file.open(filename);

        if (!file.good()) {
            std::cerr << "ERROR: Failed to open output file" << std::endl;
            return;
        }

        // Output magic number
        file << PPM_MAGIC_NUMBER << std::endl;

        // Output width and height
        file << this->horizontalRes << " " << this->verticalRes << std::endl;

        // Output maximum colour value (256 values for R, G and B)
        file << MAX_COLOUR_VALUE << std::endl;

        /**
         * PPM format specifies lines must not have more than 70 characters
         * so this variable holds the number of pixels written on the
         * current line
         */
        int lineCount = 0;

        for (int i=0; i < this->verticalRes; i++) {
            for (int j=0; j < this->horizontalRes; j++) {
                Colour& pixelColour = getPixelColour(j, i);

                if (lineCount + (3 * (MAX_COLOUR_VALUE_CHARS + 1)) > PPM_MAX_CHARS_PER_LINE) {
                    // We'll go over 70 chars per line so insert line break
                    file << std::endl;
                    lineCount = 0;
                }

                file << (int) (pixelColour.r * MAX_COLOUR_VALUE) << " ";
                file << (int) (pixelColour.g * MAX_COLOUR_VALUE) << " ";
                file << (int) (pixelColour.b * MAX_COLOUR_VALUE) << " ";

                lineCount += (3 * (MAX_COLOUR_VALUE_CHARS + 1));
            }
        }

        file.close();
    }
}
