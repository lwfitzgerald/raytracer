#include "World.h"

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

void World::addLight(Light* light) {
    this->lights.push_back(light);
}

void World::addMaterial(Material* material) {
    this->materials[material->name] = material;
}

void World::setCamera(Camera* camera) {
    this->camera = camera;
}

void World::setAmbientLight(AmbientLight* ambientLight) {
    this->ambientLight = ambientLight;
}

void World::setViewPlaneResolution(const unsigned int hres, const unsigned int vres) {
    this->viewPlane.setResolution(hres, vres);
}

void World::setViewPlanePixelSize(float pixelSize) {
    this->viewPlane.setPixelSize(pixelSize);
}
