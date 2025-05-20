#ifndef FINALPLAN_H
#define FINALPLAN_H

#include "Parameters.h"
#include <map>

class FinalPlan {
    OptimalBiome optimal_biome;
    map<string, double> making_resources;
    map<string, double> importing_resources;
    double total_price = 0;
    double total_operation_capacity = 0;

    void fillResources();

public:
    FinalPlan() {fillResources();};
    void addMakingResourceValue(string resource, double value);
    void addImportingResourceValue(string resource, double value);
    void setOptimalBiome(OptimalBiome biome) {optimal_biome = biome;};
    void print();

};

#endif // FINALPLAN_H
