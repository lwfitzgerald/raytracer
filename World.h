/*
 * World.h
 *
 *  Created on: 27 Feb 2012
 *      Author: darkip
 */

#ifndef WORLD_H_
#define WORLD_H_

#include "Prereqs.h"

#include "Utils/Colour.h"
#include "ViewPlane.h"
#include "Lights/AmbientLight.h"

class World {
public:
    Colour backgroundColour;
    ViewPlane viewPlane;

    // Ambient light in the world
    AmbientLight* ambientLight;

    // Vector of objects in the world
    std::vector<Object*> objects;

    // Vector of lights in the world
    std::vector<Light*> lights;

    World()
    :
        ambientLight(new AmbientLight),
        camera(NULL) {}

    ~World();

    void setup();
    void renderScene();

    void addObject(Object* object);

    ShadeInfo hitObjects(const Ray& ray) const;
private:
    Camera* camera;
};

#endif /* WORLD_H_ */
