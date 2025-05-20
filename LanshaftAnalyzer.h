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

class LanshaftAnalyzer {
    AnalyzingData *data;
    double left_money;

    OptimalBiome calculateCoefficients();

public:
    LanshaftAnalyzer(AnalyzingData *data, double money) : data(data), left_money(money) {};
    void operator()();
};

#endif // LANSHAFTANALYZER_H
