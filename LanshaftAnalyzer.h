#ifndef LANSHAFTANALYZER_H
#define LANSHAFTANALYZER_H

#include "AnalyzingData.h"
#include "Parameters.h"
#include <string>

using namespace std;

class MissingSuitableBiome {
public:
    MissingSuitableBiome() {};
};

class LanshaftAnalyzer {
    AnalyzingData *data;

    void calculateCoefficients();

public:
    LanshaftAnalyzer(AnalyzingData *data) : data(data) {};
    void operator()();
};

#endif // LANSHAFTANALYZER_H
