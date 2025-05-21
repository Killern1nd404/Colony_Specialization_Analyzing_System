#include "LanshaftAnalyzer.h"
#include <string>
#include <vector>
#include "Parameters.h"
#include <iostream>

using namespace std;

void LanshaftAnalyzer::writeDataInPlan() {
    plan->setOptimalBiome(optimal_biome);
    plan->addMakingResourceValue("STONE", making_resources_capacity["STONE"]);
    plan->addMakingResourceValue("WOOD", making_resources_capacity["WOOD"]);
    plan->addMakingResourceValue("CLAY", making_resources_capacity["CLAY"]);
    plan->addMakingResourceValue("COAL", making_resources_capacity["COAL"]);
    plan->addMakingResourceValue("IRON", making_resources_capacity["IRON"]);
    plan->addImportingResourceValue("STONE", importing_resources_price["STONE"]);
    plan->addImportingResourceValue("WOOD", importing_resources_price["WOOD"]);
    plan->addImportingResourceValue("CLAY", importing_resources_price["CLAY"]);
    plan->addImportingResourceValue("COAL", importing_resources_price["COAL"]);
    plan->addImportingResourceValue("IRON", importing_resources_price["IRON"]);
}

bool LanshaftAnalyzer::isHaveDrinkWater() {
    bool is_have_drink_water = false;
    for (AdditionalBiome &additional_biome : data->getAdditionalBiomes()) {
        if (additional_biome.name == "Река" || additional_biome.name == "Озеро") {
            is_have_drink_water = true;
            break;
        }
    }
    return is_have_drink_water;
}

void LanshaftAnalyzer::calculateResourceRequirements(string resource, double *price, double *capacity, double requirement) {
    for (Resource &making_resource : data->getMakingProductionResources()) {
        if (making_resource.name == resource) {
            if (making_resource.max_value*(left_operation_capacity-*capacity) >= requirement) {
                making_resources_capacity_temp[resource] = requirement / making_resource.max_value;
                *capacity += requirement / making_resource.max_value;
                return;
            } else {
                for (ImportResource &importing_resource : data->getImportingProductionResources()) {
                    if (importing_resource.name == resource) {
                        if (making_resource.max_value*(left_operation_capacity-*capacity) + min(importing_resource.max_value, (left_money - *price)/importing_resource.price) >= requirement) {
                            for (int i = 9; i >= 0; i--) {
                                double capacity_temp = i*0.1;
                                if (capacity_temp + *capacity <= left_operation_capacity) {
                                    double price_temp = (requirement - making_resource.max_value*capacity_temp)/importing_resource.price;
                                    if (price_temp > left_money - *price) {
                                        throw NotEnoughtResources();
                                    }
                                    making_resources_capacity_temp[resource] = capacity_temp;
                                    *capacity += capacity_temp;
                                    *price += price_temp;
                                    return;
                                }
                            }
                        } else {
                            throw NotEnoughtResources();
                        }
                    }
                }
            }
        }
    }
}

void LanshaftAnalyzer::operator()() {
    if (!isHaveDrinkWater()) {
        throw DrinkWaterSourceNotFounded();
    }

    map<string, double> making_resources;
    for (Resource &resource : data->getMakingProductionResources()) {
        making_resources[resource.name] = resource.max_value;
    }
    double min_square = data->getMinRequiredSquare();
    vector<Biome> biomes = data->getMainBiomes();
    map<string, vector<ResourcesRequirements>> biomes_requirements = data->getBiomesRequiremets();
    for (Biome &biome : biomes) {
        if (biome.square >= min_square) {
            for (ResourcesRequirements &requirements : biomes_requirements[biome.name]) {
                double price = 0;
                double min_operation_capacity = 0;
                bool is_enought_resources = true;
                try {
                    calculateResourceRequirements("STONE", &price, &min_operation_capacity, requirements.stone);
                    calculateResourceRequirements("WOOD", &price, &min_operation_capacity, requirements.wood);
                    calculateResourceRequirements("COAL", &price, &min_operation_capacity, requirements.coal);
                    calculateResourceRequirements("CLAY", &price, &min_operation_capacity, requirements.clay);
                    calculateResourceRequirements("IRON", &price, &min_operation_capacity, requirements.iron);
                } catch (NotEnoughtResources error) {
                    is_enought_resources = false;
                }
                if (is_enought_resources) {
                    double potential = (1 - min_operation_capacity) * biome.square;
                    if (potential > total_operation_capacity && min_operation_capacity <= 1) {
                        total_operation_capacity = min_operation_capacity;
                        optimal_biome.setBiome(biome.name, biome.square, requirements.stone, requirements.wood,
                                               requirements.clay, requirements.iron, requirements.coal);
                        making_resources_capacity = making_resources_capacity_temp;
                        making_resources_capacity_temp.clear();
                        importing_resources_price = importing_resources_price_temp;
                        importing_resources_price_temp.clear();
                    }
                }

            }
        }
    }

    if (optimal_biome.name == "NONE") {
        throw SuitableBiomeNotFounded();
    } else {
        making_resources_capacity[data->getMakingProductionResources().begin()->name] += left_operation_capacity - total_operation_capacity;
        writeDataInPlan();
    }
}
