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

#include "Object.h"
#include "Colour.h"
#include "ViewPlane.h"

class World {
public:
    World() {}
    ~World();

    void setup();
    void renderScene() const;

    void addObject(Object* object);
private:
    Colour backgroundColour;
    ViewPlane viewPlane;

    // Vector of objects in the world
    std::vector<Object*> objects;
};

#endif /* WORLD_H_ */
