#include "LanshaftAnalyzer.h"
#include <string>
#include <vector>
#include "Parameters.h"

using namespace std;

//LanshaftAnalyzer::LanshaftAnalyzer() {};

void LanshaftAnalyzer::operator()() {
    //data->filterMainBiomes();
    //vector<string> biomes_names = data->getMainBiomesNames();
    //vector<double> biomes_squares = data->getMainBiomesSquares();
    vector<Biome> biomes = data->getMainBiomes();

    if (biomes.empty()) {
        throw MissingSuitableBiome();
    }
}

void LanshaftAnalyzer::calculateCoefficients() {

}
