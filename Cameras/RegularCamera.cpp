/*
 * RegularCamera.cpp
 *
 *  Created on: 29 Feb 2012
 *      Author: darkip
 */

#include "RegularCamera.h"

#include "../Utils/Ray.h"
#include "../Utils/ShadeInfo.h"
#include "../World.h"
#include "../ViewPlane.h"

void RegularCamera::renderScene(World& world) const {
    ViewPlane& viewPlane = world.viewPlane;

    Ray ray;
    ShadeInfo shadeInfo;
    double x, y;

    ray.origin = eye;

    for (int i=0; i < viewPlane.verticalRes; i++) {
        for (int j=0; j < viewPlane.horizontalRes; j++) {
            x = viewPlane.pixelSize * (j - 0.5 * viewPlane.horizontalRes + 0.5);
            y = viewPlane.pixelSize * (0.5 * viewPlane.verticalRes - i - 0.5);

            ray.direction = x * this->u + y * this->v - this->viewPlaneDistance * this->w;
            ray.direction.normalise();

            // Intersect with all objects in scene
            shadeInfo = world.hitObjects(ray);

            if (shadeInfo.hit) {
                viewPlane.setPixelColour(j, i, shadeInfo.colour);
            } else {
                viewPlane.setPixelColour(j, i, world.backgroundColour);
            }
        }
    }

    // Write output image
    world.viewPlane.writePPM(OUTPUT_FILENAME);
}

void RegularCamera::setViewPlaneDistance(const double& distance) {
    this->viewPlaneDistance = distance;
}
