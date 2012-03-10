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
#include "Lights/DirectionalLight.h"
#include "Materials/Lambert.h"

World::~World() {
    // Delete the camera
    delete this->camera;

    // Delete the ambient light
    delete this->ambientLight;

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

    this->backgroundColour = BLACK;

    // Configure the camera
    this->camera = new RegularCamera();
    ((RegularCamera*) this->camera)->setViewPlaneDistance(500);
    this->camera->setRollAngle(0);
    this->camera->calcUVW();

    this->ambientLight->setIntensity(0);

    DirectionalLight* directionalLight = new DirectionalLight();
    directionalLight->setDirection(Vector3(100, 100, 200));
    this->lights.push_back(directionalLight);

    Lambert* redLambert = new Lambert();
    redLambert->setDiffuseColour(RED);
    redLambert->setAmbientReflection(1);
    redLambert->setDiffuseReflection(1);

    Lambert* blueLambert = new Lambert();
    blueLambert->setDiffuseColour(BLUE);
    blueLambert->setAmbientReflection(1);
    blueLambert->setDiffuseReflection(1);

    Lambert* greenLambert = new Lambert();
    greenLambert->setDiffuseColour(GREEN);
    greenLambert->setAmbientReflection(1);
    greenLambert->setDiffuseReflection(1);

    Sphere* sphere1 = new Sphere(Point3(-80, 0, 0), 80);
    sphere1->setMaterial(redLambert);
    addObject(sphere1);

    Sphere* sphere2 = new Sphere(Point3(80, 0, 0), 80);
    sphere2->setMaterial(blueLambert);
    addObject(sphere2);

    Plane* plane = new Plane(Point3(0, -100, 0), Normal(0, 1, 0));
    plane->setMaterial(greenLambert);
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
        shadeInfo.colour = tminHitObject->material->shade(shadeInfo, *this);
    }

    return shadeInfo;
}

void World::addObject(Object* object) {
    this->objects.push_back(object);
}
