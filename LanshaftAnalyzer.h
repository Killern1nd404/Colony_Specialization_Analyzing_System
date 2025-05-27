
#ifndef LANSHAFTANALYZER_H
#define LANSHAFTANALYZER_H

#include "AnalyzingData.h"
#include "Parameters.h"
#include <string>
#include "FinalPlan.h"

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
    FinalPlanBuilder *plan_builder;
    double left_money;
    double left_operation_capacity;
    map<string, double> making_resources_capacity;
    map<string, double> importing_resources_price;
    map<string, double> making_resources_capacity_temp;
    map<string, double> importing_resources_price_temp;
    double total_operation_capacity = 0;
    double total_price = 0;
    OptimalBiome optimal_biome;

    void calculateResourceRequirements(string resource, double *price, double *capacity, double requirement);
    void writeDataInPlan();
    bool isHaveDrinkWater();

public:
    //LanshaftAnalyzer(AnalyzingData *data, FinalPlanBuilder *plan_builder, double money, double operation_capacity) : data(data), plan_builder(plan_builder), left_money(money), left_operation_capacity(operation_capacity) {};
    LanshaftAnalyzer() {};
    void setAllData(AnalyzingData *data_, FinalPlanBuilder *plan_builder_, double money, double operation_capacity);
    void operator()();
};

#endif // LANSHAFTANALYZER_H
