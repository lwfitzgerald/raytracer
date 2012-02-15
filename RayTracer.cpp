/*
 * RayTracer.cpp
 *
 *  Created on: 15 Feb 2012
 *      Author: darkip
 */

#include "RayTracer.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

RayTracer::RayTracer() {
    // TODO Auto-generated constructor stub

}

RayTracer::~RayTracer() {
    // TODO Auto-generated destructor stub
}

void RayTracer::parseInput(int argc, char *argv[]) {
    // TODO parse input file

    if (argc != 2) {
        std::cerr << "Incorrect number of arguments\n";
        std::exit(1);
    }

    // Open input file
    std::ifstream inputFile (argv[0]);

    if (inputFile.is_open()) {
        std::string line;

        while (inputFile.good()) {
            getline(inputFile, line);
            // TODO: Handle input line!
        }
    } else {
        std::cerr << "Could not open input file\n";
        std::exit(1);
    }
}
