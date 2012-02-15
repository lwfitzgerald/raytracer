#include "RayTracer.h"

int main(int argc, char *argv[]) {
    RayTracer* rayTracer = new RayTracer();

    rayTracer->parseInput(argc, argv);

    return 0;
}
