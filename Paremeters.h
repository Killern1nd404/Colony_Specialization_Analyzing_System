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
    double getStone() {return stone;};
    double getWood() {return wood;};
    double getClay() {return clay;};
    double getCoal() {return coal;};
    double getIron() {return iron;};
};

map<string, vector<ResourcesRequirements>> biomes_requirements = {
    {"PLAIN", {{10, 3, 2, 0, 1}, {8, 2, 2, 0, 3}, {2, 4, 8, 0, 2}}},
    {"HILLS", {{12, 4, 3, 0, 1}, {9, 3, 3, 0, 3}, {3, 5, 9, 0, 2}}},
    {"MOUNTAINS", {{10, 18, 0, 0, 6}, {4, 18, 8, 0, 6}}},
    {"SWAMP", {{10, 15, 0, 0, 4}, {4, 18, 6, 0, 4}}},
    {"FOREST", {{10, 3, 2, 0, 2}, {8, 2, 2, 0, 4}, {2, 4, 8, 0, 3}}}
};

#endif // PAREMETERS_H
