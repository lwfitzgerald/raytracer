/*
 * ViewPlane.cpp
 *
 *  Created on: 27 Feb 2012
 *      Author: darkip
 */

#include "ViewPlane.h"

void ViewPlane::setResolution(const int horizontal, const int vertical) {
    this->horizontalRes = horizontal;
    this->verticalRes = vertical;
}

void ViewPlane::setPixelSize(const float pixelSize) {
    this->pixelSize = pixelSize;
}

void ViewPlane::setGamma(const float gamma) {
    this->gamma = gamma;
    this->invGamma = 1 / gamma;
}
