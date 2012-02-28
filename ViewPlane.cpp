/*
 * ViewPlane.cpp
 *
 *  Created on: 27 Feb 2012
 *      Author: darkip
 */

#include "ViewPlane.h"

#include <iostream>
#include <fstream>

#define PPM_MAGIC_NUMBER       "P3" // PPM magic number
#define PPM_MAX_CHARS_PER_LINE 70   // Maximum number of characters per line
#define MAX_COLOUR_VALUE       255  // Maximum colour value
#define MAX_COLOUR_VALUE_CHARS 3    // Maximum number of characters for a colour value

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

void ViewPlane::setGamma(const float gamma) {
    this->gamma = gamma;
    this->invGamma = 1 / gamma;
}

void ViewPlane::setPixelColour(const int x, const int y, const Colour& colour) {
    pixelColours[x * this->verticalRes + y] = colour;
}

Colour& ViewPlane::getPixelColour(const int x, const int y) const {
    return pixelColours[x * this->verticalRes + y];
}

void ViewPlane::writePPM(char* filename) const {
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

    for (int i=0; i < this->horizontalRes; i++) {
        for (int j=0; j < this->verticalRes; j++) {
            Colour& pixelColour = getPixelColour(i, j);

            if (lineCount + (3 * (MAX_COLOUR_VALUE_CHARS + 1)) > PPM_MAX_CHARS_PER_LINE) {
                // We'll go over 70 chars per line so insert line break
                file << std::endl;
            }

            file << pixelColour.r * MAX_COLOUR_VALUE << " ";
            file << pixelColour.g * MAX_COLOUR_VALUE << " ";
            file << pixelColour.b * MAX_COLOUR_VALUE << " ";
        }
    }

    //file.flush();
    file.close();
}
