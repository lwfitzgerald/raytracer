#ifndef BVHNODE_H
#define BVHNODE_H

#include "../Prereqs.h"

namespace Raytracer {
    struct BVHNode {
        BVHNode() {
            left = NULL;
            right = NULL;
            objects = NULL;
        }

        BoundingBox boundingBox;
        BVHNode* left;
        BVHNode* right;
        std::vector<Object*>* objects;
    };
}

#endif /* BVHNODE_H_ */
