/*
 * ViewPlane.h
 *
 *  Created on: 27 Feb 2012
 *      Author: darkip
 */

#ifndef VIEWPLANE_H_
#define VIEWPLANE_H_

class ViewPlane {
public:
    int horizontalRes;
    int verticalRes;
    float pixelSize;
    float gamma;
    float invGamma;

    ViewPlane() {}
    ~ViewPlane() {}

    void setResolution(const int horizontal, const int vertical);
    void setPixelSize(const float pixelSize);
    void setGamma(const float gamma);
};

#endif /* VIEWPLANE_H_ */
