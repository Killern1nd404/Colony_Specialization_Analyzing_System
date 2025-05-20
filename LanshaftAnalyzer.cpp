#include "LanshaftAnalyzer.h"
#include <string>
#include <vector>
#include "Parameters.h"
#include <iostream>

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

double LanshaftAnalyzer::calculateResourceRequirements(string resource, double *price, double requirement) {
    for (Resource &making_resource : data->getMakingProductionResources()) {
        if (making_resource.name == resource) {
            if (making_resource.max_value < requirement) {
                for (ImportResource &importing_resource : data->getImportingProductionResources()) {
                    if (importing_resource.name == resource) {
                        double resource_price = (requirement - making_resource.max_value) * importing_resource.price;
                        if (importing_resource.max_value < requirement - making_resource.max_value || resource_price > left_money) {
                            throw NotEnoughtResources();
                        }
                        *price += resource_price;
                        left_money -= resource_price;
                        importing_resources_price_temp[resource] = resource_price;
                        break;
                    }
                }
            }

            making_resources_capacity_temp[resource] = requirement / making_resource.max_value;
            return requirement / making_resource.max_value;
        }
    }
}

void LanshaftAnalyzer::operator()() {
    bool is_have_drink_water = false;
    for (AdditionalBiome &additional_biome : data->getAdditionalBiomes()) {
        if (additional_biome.name == "Река" || additional_biome.name == "Озеро") {
            is_have_drink_water = true;
            break;
        }
    }
    if (!is_have_drink_water) {
        throw DrinkWaterSourceNotFounded();
    }

    vector<Biome> biomes = data->getMainBiomes();
    map<string, vector<ResourcesRequirements>> biomes_requirements = data->getBiomesRequiremets();
    map<string, double> making_resources;
    for (Resource &resource : data->getMakingProductionResources()) {
        making_resources[resource.name] = resource.max_value;
    }
    double min_square = data->getMinRequiredSquare();
    double max_coefficient = 0;

    for (Biome &biome : biomes) {
        if (biome.square >= min_square) {
            for (ResourcesRequirements &requirements : biomes_requirements[biome.name]) {
                double price = 0;
                bool is_enought_resources = true;
                double min_required_operation_capacity = 0;
                try {
                    min_required_operation_capacity += calculateResourceRequirements("STONE", &price, requirements.stone) +
                                                            calculateResourceRequirements("WOOD", &price, requirements.wood) +
                                                            calculateResourceRequirements("COAL", &price, requirements.coal) +
                                                            calculateResourceRequirements("CLAY", &price, requirements.clay) +
                                                            calculateResourceRequirements("IRON", &price, requirements.iron);
                } catch (NotEnoughtResources error) {
                    is_enought_resources = false;
                }
                if (is_enought_resources) {
                    double potential = (1 - min_required_operation_capacity) * biome.square;
                    if (potential > max_coefficient) {
                        max_coefficient = potential;
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
        //data->setOptimalBiome(optimal_biome);
        writeDataInPlan();
    }


}

/*void LanshaftAnalyzer::calculateCoefficients() {

}*/
