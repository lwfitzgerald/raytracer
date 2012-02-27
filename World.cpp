/*
 * World.cpp
 *
 *  Created on: 27 Feb 2012
 *      Author: darkip
 */

#include "World.h"

void World::setup() {
    // First specify the view plane parameters
    viewPlane.setResolution(640, 480); // TODO: Move these "magic numbers" out of this file
    viewPlane.setPixelSize(1.0);
    viewPlane.setGamma(1.0);

    // Set the background colour
    //backgroundColour =
}

void World::renderScene() const {

}
