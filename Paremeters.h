#ifndef PAREMETERS_H
#define PAREMETERS_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class ResourcesRequirements {
    double stone;
    double wood;
    double clay;
    double coal;
    double iron;

public:
    ResourcesRequirements(double stone, double wood, double clay, double coal, double iron) : stone(stone), wood(wood), clay(clay),
        coal(coal), iron(iron) {};
};

map<string, int> biomes_requirements = {
    {"PLAIN", 1}
};

#endif // PAREMETERS_H
