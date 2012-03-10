/*
 * World.h
 *
 *  Created on: 27 Feb 2012
 *      Author: darkip
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <vector>

#include "Prereqs.h"

#include "Objects/Object.h"
#include "Utils/Colour.h"
#include "ViewPlane.h"

class World {
public:
    Colour backgroundColour;
    ViewPlane viewPlane;

    // Vector of objects in the world
    std::vector<Object*> objects;

    World() {}
    ~World();

    void setup();
    void renderScene();

    void addObject(Object* object);

    ShadeInfo hitObjects(const Ray& ray) const;
private:
    Camera* camera;
};

#endif /* WORLD_H_ */
