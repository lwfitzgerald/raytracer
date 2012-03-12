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
#include "Lights/PointLight.h"
#include "Materials/Lambert.h"
#include "Materials/Phong.h"

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

    PointLight* pointLight = new PointLight();
    pointLight->setLocation(Point3(100, 100, 100));
    this->lights.push_back(pointLight);

    PointLight* pointLight2 = new PointLight();
    pointLight2->setLocation(Point3(-100, 100, 100));
    this->lights.push_back(pointLight2);

    Phong* redPhong = new Phong();
    redPhong->setDiffuseColour(RED);
    redPhong->setAmbientReflection(1);
    redPhong->setDiffuseReflection(1);

    Phong* bluePhong = new Phong();
    bluePhong->setDiffuseColour(BLUE);
    bluePhong->setAmbientReflection(1);
    bluePhong->setDiffuseReflection(1);

    Phong* grayPhong = new Phong();
    grayPhong->setDiffuseColour(GREY);
    grayPhong->setAmbientReflection(1);
    grayPhong->setDiffuseReflection(1);

    Sphere* sphere1 = new Sphere(Point3(-80, 0, 0), 80);
    sphere1->setMaterial(redPhong);
    addObject(sphere1);

    Sphere* sphere2 = new Sphere(Point3(80, 0, 0), 80);
    sphere2->setMaterial(bluePhong);
    addObject(sphere2);

    Plane* plane = new Plane(Point3(0, -100, 0), Normal(0, 1, 0));
    plane->setMaterial(grayPhong);
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
            shadeInfo.ray = ray;
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
