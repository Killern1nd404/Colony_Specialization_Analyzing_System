#include "LanshaftAnalyzer.h"
#include <string>
#include <vector>
#include "Parameters.h"
#include <iostream>

using namespace std;

//LanshaftAnalyzer::LanshaftAnalyzer() {};

void LanshaftAnalyzer::operator()() {
    vector<Biome> biomes = data->getMainBiomes();
    map<string, vector<ResourcesRequirements>> biomes_requirements = data->getBiomesRequiremets();
    map<string, double> making_resources;
    for (Resource &resource : data->getMakingProductionResources()) {
        making_resources[resource.name] = resource.max_value;
    }
    double min_square = data->getMinRequiredSquare();
    double max_coefficient = 0;
    OptimalBiome optimal_biome;


    for (Biome &biome : biomes) {
        if (biome.square >= min_square) {
            for (ResourcesRequirements &requirements : biomes_requirements[biome.name]) {
                double min_required_operation_capacity = requirements.stone/making_resources["STONE"] +
                                                         requirements.clay/making_resources["CLAY"] +
                                                         requirements.coal/making_resources["COAL"] +
                                                         requirements.iron/making_resources["IRON"] +
                                                         requirements.wood/making_resources["WOOD"];
                cout << biome.name << ": " << (1 - min_required_operation_capacity) * biome.square << endl;
                double potential = (1 - min_required_operation_capacity) * biome.square;
                if (potential > max_coefficient) {
                    max_coefficient = potential;
                    optimal_biome.setBiome(biome.name, biome.square, requirements.stone, requirements.wood,
                                           requirements.clay, requirements.iron, requirements.coal);
                }
            }
        }
    }

    if (optimal_biome.name == "NONE") {
        throw SuitableBiomeNotFounded();
    } else {
        data->setOptimalBiome(optimal_biome);
    }


}

/*void LanshaftAnalyzer::calculateCoefficients() {

}*/
