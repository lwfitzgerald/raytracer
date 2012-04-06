#include "Object.h"
#include "../World.h"

namespace Raytracer {
    void Object::setMaterial(Material* material) {
        this->material = material;
    }

    void Object::fetchMaterial(std::istringstream& iss, const World& world) {
        std::string materialName;

        iss >> materialName;

        material = world.materials.at(materialName);
    }
}
