/*
 * World.cpp
 *
 *  Created on: 27 Feb 2012
 *      Author: darkip
 */

#include "World.h"

#include <limits>

#include "Utils/Ray.h"
#include "Utils/ShadeInfo.h"
#include "Utils/Point3.h"
#include "Objects/Plane.h"
#include "Objects/Sphere.h"
#include "Cameras/RegularCamera.h"

World::~World() {
    // Delete the camera
    delete this->camera;

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

    this->backgroundColour = BLUE;

    // Configure the camera
    this->camera = new RegularCamera();
    ((RegularCamera*) this->camera)->setViewPlaneDistance(50);
    this->camera->setRollAngle(45);
    this->camera->calcUVW();

    Sphere* sphere1 = new Sphere(Point3(0, 0, -25), 80);
    sphere1->colour = RED;
    addObject(sphere1);

    Sphere* sphere2 = new Sphere(Point3(0, 40, -25), 80);
    sphere2->colour = BLUE;
    addObject(sphere2);

    Plane* plane = new Plane(Point3(0, 0, -50), Normal(0, 0, 1));
    plane->colour = GREEN;
    addObject(plane);
}

void World::renderScene() {
    camera->renderScene(*this);
}

ShadeInfo World::hitObjects(const Ray& ray) const {
    double t;
    ShadeInfo shadeInfo;
    Object* tminHitObject = NULL;

    // Set tmin to infinity
    double tmin = std::numeric_limits<double>::infinity();

    for (unsigned int i=0; i < this->objects.size(); i++) {
        if (this->objects[i]->hit(ray, t) && t < tmin) {
            shadeInfo.hit = true;
            tminHitObject = this->objects[i];
            tmin = t;
        }
    }

    if (shadeInfo.hit) {
        // Some object was hit so get the shading information for it
        tminHitObject->getShadeInfo(shadeInfo, ray, tmin);
        shadeInfo.colour = tminHitObject->colour;
    }

    return shadeInfo;
}

void World::addObject(Object* object) {
    this->objects.push_back(object);
}
