#ifndef LANSHAFTANALYZER_H
#define LANSHAFTANALYZER_H

#include "AnalyzingData.h"
#include "Parameters.h"
#include <string>
#include "FinalPlan.h"

using namespace std;

class SuitableBiomeNotFounded {
public:
    SuitableBiomeNotFounded() {};
};

class DrinkWaterSourceNotFounded {
public:
    DrinkWaterSourceNotFounded() {};
};

class NotEnoughtResources {
public:
    NotEnoughtResources() {};
};

class LanshaftAnalyzer {
    AnalyzingData *data;
    FinalPlan *plan;
    double left_money;
    map<string, double> making_resources_capacity;
    map<string, double> importing_resources_price;
    map<string, double> making_resources_capacity_temp;
    map<string, double> importing_resources_price_temp;
    OptimalBiome optimal_biome;

    OptimalBiome calculateCoefficients();
    double calculateResourceRequirements(string resource, double *price, double requirement);
    void writeDataInPlan();

public:
    LanshaftAnalyzer(AnalyzingData *data, FinalPlan *plan, double money) : data(data), plan(plan), left_money(money) {};
    void operator()();
};

#endif // LANSHAFTANALYZER_H
