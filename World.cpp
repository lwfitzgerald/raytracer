/*
 * World.cpp
 *
 *  Created on: 27 Feb 2012
 *      Author: darkip
 */

#include "World.h"

#include <limits>

#include "Ray.h"
#include "ShadeInfo.h"
#include "Point3.h"
#include "Sphere.h"

#define VIEW_PLANE_Z 100;

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

    Sphere* test = new Sphere(Point3(0, 0, 0), 85);
    addObject(test);

    this->viewPlane.writePPM(OUTPUT_FILENAME);

    // Set the background colour
    //backgroundColour =
}

void World::renderScene() {
    Colour pixelColour;
    Ray ray;
    double x, y, z = VIEW_PLANE_Z;

    for (int i=0; i < this->viewPlane.horizontalRes; i++) {
        for (int j=0; j < this->viewPlane.verticalRes; j++) {
            x = this->viewPlane.pixelSize * (j - 0.5 * (this->viewPlane.horizontalRes - 1.0));
            y = this->viewPlane.pixelSize * (j - 0.5 * (this->viewPlane.horizontalRes - 1.0));
            ray.origin = Point3(x, y, z);

            this->viewPlane.setPixelColour(i, j, pixelColour);
        }
    }

    // Write output image
    this->viewPlane.writePPM(OUTPUT_FILENAME);
}

ShadeInfo World::hitObjects(const Ray& ray) const {
    ShadeInfo shadeInfo;
    double t;

    // Set tmin to largest possible double value
    double tmin = std::numeric_limits<double>::max();

    for (unsigned int i=0; i < this->objects.size(); i++) {
        if (this->objects[i]->hit(ray, t, shadeInfo) && t < tmin) {
            shadeInfo.hit = true;
            tmin = t;
            shadeInfo.colour = objects[i]->colour;
        }
    }

    return shadeInfo;
}

void World::addObject(Object* object) {
    this->objects.push_back(object);
}
