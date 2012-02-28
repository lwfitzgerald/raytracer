/*
 * World.cpp
 *
 *  Created on: 27 Feb 2012
 *      Author: darkip
 */

#include "World.h"

World::~World() {
    // On destruction, delete all objects

    std::vector<Object*>::iterator itr;

    for (itr=this->objects.begin(); itr < this->objects.end(); itr++) {
        delete *itr;
    }
}

void World::setup() {
    // First specify the view plane parameters
    this->viewPlane.setResolution(HORIZONTAL_RES, VERTICAL_RES);
    this->viewPlane.setPixelSize(PIXEL_SIZE);
    this->viewPlane.setGamma(GAMMA);

    this->viewPlane.setPixelColour(0, 0, RED);
    this->viewPlane.writePPM("output.ppm");

    // Set the background colour
    //backgroundColour =
}

void World::renderScene() const {

}

void World::addObject(Object* object) {
    this->objects.push_back(object);
}
