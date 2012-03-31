#include "Object.h"
#include "../World.h"

void Object::setMaterial(Material* material) {
    this->material = material;
}

void Object::fetchMaterial(std::istringstream& iss, World& world) {
    std::string materialName;

    iss >> materialName;

    material = world.materials[materialName];
}
