#ifndef LANSHAFTANALYZER_H
#define LANSHAFTANALYZER_H

#include "AnalyzingData.h"
#include "Parameters.h"
#include <string>

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
    double left_money;

    OptimalBiome calculateCoefficients();
    double calculateResourceRequirements(string resource, double *price, double requirement);
    double calculateStoneRequirements(double *price, double requirement);
    double calculateWoodRequirements(double *price, double requirement);
    double calculateClayRequirements(double *price, double requirement);
    double calculateIronRequirements(double *price, double requirement);
    double calculateCoalRequirements(double *price, double requirement);

public:
    LanshaftAnalyzer(AnalyzingData *data, double money) : data(data), left_money(money) {};
    void operator()();
};

#endif // LANSHAFTANALYZER_H
