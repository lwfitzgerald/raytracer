#include "World.h"
#include "Utils/SceneReader.h"

using namespace Raytracer;

int main(int argc, char *argv[]) {
    if (argc < 1) {
        std::cerr << "Input file not specified" << std::endl;
        return 1;
    }

    World world;

    // Fill the world!
    SceneReader::buildScene(argv[1], world);

    // Build the bounding volume hierarchy
    world.buildBVH();

    // Render the scene
    world.renderScene();

    return 0;
}
