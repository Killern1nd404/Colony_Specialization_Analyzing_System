#include "LanshaftAnalyzer.h"
#include <string>
#include <vector>

using namespace std;

//LanshaftAnalyzer::LanshaftAnalyzer() {};

void LanshaftAnalyzer::operator()() {
    data->filterMainBiomes();
    vector<string> biomes_names = data->getMainBiomesNames();
    vector<double> biomes_squares = data->getMainBiomesSquares();

    if (biomes_names.empty()) {
        throw MissingSuitableBiome();
    }
}
