#ifndef LANSHAFTANALYZER_H
#define LANSHAFTANALYZER_H

#include "AnalyzingData.h"
//#include "Paremeters.h"
#include <string>

using namespace std;

class MissingSuitableBiome {
public:
    MissingSuitableBiome() {};
};

/*class OptimalBiome : public ResourcesRequirements {
    string biome;

public:
    OptimalBiome(ResourcesRequirements data, string biome) : ResourcesRequirements(data.getStone(), data.getWood(), data.getClay(),
                                data.getCoal(), data.getIron()), biome(biome) {};
};*/

class LanshaftAnalyzer {
    AnalyzingData *data;

    void calculateCoefficients();

public:
    LanshaftAnalyzer(AnalyzingData *data) : data(data) {};
    void operator()();
};

#endif // LANSHAFTANALYZER_H
