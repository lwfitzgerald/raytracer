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
#include "Objects/Disc.h"
#include "Objects/Triangle.h"
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
    this->camera->setEyePoint(Point3(0, 0, 200));
    this->camera->setLookAtPoint(Point3(0, 0, -200));
    ((RegularCamera*) this->camera)->setViewPlaneDistance(500);
    this->camera->setRollAngle(0);
    this->camera->calcUVW();

    this->ambientLight->setIntensity(0);

    PointLight* pointLight = new PointLight();
    pointLight->setIntensity(1);
    pointLight->setLocation(Point3(0, 0, 100));
    this->lights.push_back(pointLight);

    PointLight* pointLight2 = new PointLight();
    pointLight2->setIntensity(0.5);
    pointLight2->setLocation(Point3(-100, 100, 100));
    //this->lights.push_back(pointLight2);

    Phong* redPhong = new Phong();
    redPhong->setDiffuseColour(RED);
    redPhong->setAmbientReflection(1);
    redPhong->setDiffuseReflection(1);
    redPhong->setSpecularReflection(0.3);

    Phong* bluePhong = new Phong();
    bluePhong->setDiffuseColour(BLUE);
    bluePhong->setAmbientReflection(1);
    bluePhong->setDiffuseReflection(1);
    bluePhong->setSpecularReflection(0.3);

    Lambert* grayLambert = new Lambert();
    grayLambert->setDiffuseColour(GREY);
    grayLambert->setAmbientReflection(1);
    grayLambert->setDiffuseReflection(0.5);

    Sphere* sphere1 = new Sphere(Point3(0, 60, 0), 20);
    sphere1->setMaterial(redPhong);
    addObject(sphere1);

    Sphere* sphere2 = new Sphere(Point3(-60, 0, 100), 20);
    sphere2->setMaterial(bluePhong);
    addObject(sphere2);

    Disc* disc = new Disc(Point3(0,0,20), Normal(0, 0, 1), 20);
    disc->setMaterial(bluePhong);
    addObject(disc);

    Triangle* triangle = new Triangle(Point3(-50, -40, 0), Point3(-50, 40, 0), Point3(50, 0, 0));
    triangle->setMaterial(redPhong);
    addObject(triangle);

    Plane* leftPlane = new Plane(Point3(-200, 0, 0), Normal(1, 0, 0));
    leftPlane->setMaterial(grayLambert);
    addObject(leftPlane);

    Plane* rightPlane = new Plane(Point3(200, 0, 0), Normal(-1, 0, 0));
    rightPlane->setMaterial(grayLambert);
    addObject(rightPlane);

    Plane* backPlane = new Plane(Point3(0, 0, -200), Normal(0, 0, 1));
    backPlane->setMaterial(grayLambert);
    addObject(backPlane);

    Plane* frontPlane = new Plane(Point3(0, 0, 200), Normal(0, 0, -1));
    frontPlane->setMaterial(grayLambert);
    addObject(frontPlane);

    Plane* topPlane = new Plane(Point3(0, 200, 0), Normal(0, -1, 0));
    topPlane->setMaterial(grayLambert);
    addObject(topPlane);

    Plane* bottomPlane = new Plane(Point3(0, -200, 0), Normal(0, 1, 0));
    bottomPlane->setMaterial(grayLambert);
    addObject(bottomPlane);
}

void World::renderScene() {
    camera->renderScene(*this);
}

ShadeInfo World::hitObjects(const Ray& ray, const unsigned int depth) const {
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

        shadeInfo.colour = tminHitObject->material->shade(shadeInfo, *this, depth);
    }

    return shadeInfo;
}

void World::addObject(Object* object) {
    this->objects.push_back(object);
}
