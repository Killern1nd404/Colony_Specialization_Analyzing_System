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
    void setTotalPrice(double price) {total_price = price;};
    OptimalBiome getOptimalBiome() {return optimal_biome;};
    map<string, double> getMakingResources() {return making_resources;};
    map<string, double> getImportingResources() {return importing_resources;};
    double getTotalPrice() {return total_price;};
    double getTotalOperatingCapacity() {return total_operation_capacity;};
    void clearPlan();
};
\
class FinalPlanBuilder {
    FinalPlan plan;

public:
    FinalPlanBuilder() {};
    void addMakingResourceValue(string resource, double value) {plan.addMakingResourceValue(resource, value);};
    void addImportingResourceValue(string resource, double value) {plan.addImportingResourceValue(resource, value);};
    void setOptimalBiome(OptimalBiome biome) {plan.setOptimalBiome(biome);};
    void setTotalPrice(double price) {plan.setTotalPrice(price);};
    FinalPlan returnPlan() {return plan;};
    void clearPlan() {plan.clearPlan();};
};

#endif // FINALPLAN_H
