#ifndef CONSTANTS_H_
#define CONSTANTS_H_

// Render settings
#define MAX_TRACE_DEPTH 10
#define OUTPUT_FILENAME "output.ppm"

// Number of objects in a BVH leaf node (must be 2+)
#define MAX_BVH_LEAF_OBJECTS 2

// Accuracy tolerance value
#define EPSILON 0.001

// Define some colours
#define WHITE          Colour(1, 1, 1)

#define PI 3.14159265358979323846

#endif /* CONSTANTS_H_ */
