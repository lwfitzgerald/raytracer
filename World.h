#ifndef WORLD_H_
#define WORLD_H_

#include "Prereqs.h"

#include "Utils/Colour.h"
#include "Utils/ShadeInfo.h"
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

    ShadeInfo hitObjects(const Ray& ray) const {
        return hitObjects(ray, 1);
    }

    ShadeInfo hitObjects(const Ray& ray, const unsigned int depth) const;
private:
    Camera* camera;
};

#endif /* WORLD_H_ */
