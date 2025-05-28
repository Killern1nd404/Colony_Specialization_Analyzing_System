#include "AnalyzingData.h"
#include <string>
#include <vector>
#include "Parameters.h"

AnalyzingData::AnalyzingData() {
}

void AnalyzingData::clearData() {
    if (!make_production_resources.empty()) {
        make_production_resources.clear();
        make_food_resources.clear();
        import_production_resources.clear();
        import_food_resources.clear();
        main_biomes.clear();
        additional_biomes.clear();
    }
}

void AnalyzingData::addMakingProductionResource(string name, double value) {
    bool is_added = false;
    for (int i = 0; i < make_production_resources.size(); i++) {
        if (value >= make_production_resources[i].max_value) {
            make_production_resources.insert(make_production_resources.cbegin() + i, {name, value});
            is_added = true;
            break;
        }
    }
    if (!is_added) {
        make_production_resources.push_back({name, value});
    }
}

void AnalyzingData::addMakingFoodResource(string name, double value) {
    bool is_added = false;
    for (int i = 0; i < make_food_resources.size(); i++) {
        if (value >= make_food_resources[i].max_value) {
            make_food_resources.insert(make_food_resources.cbegin(),
                                       {name, value, parameters.food_resources_nutritional_value[name]});
            is_added = true;
            break;
        }
    }
    if (!is_added) {
        make_food_resources.push_back({name, value, parameters.food_resources_nutritional_value[name]});
    }
}

void AnalyzingData::addImportingProductionResource(string name, double value, double price) {
    bool is_added = false;
    for (int i = 0; i < import_production_resources.size(); i++) {
        if (value >= import_production_resources[i].max_value) {
            import_production_resources.insert(import_production_resources.cbegin() + i, {name, value, price});
            is_added = true;
            break;
        }
    }
    if (!is_added) {
        import_production_resources.push_back({name, value, price});
    }
}

void AnalyzingData::addImportingFoodResource(string name, double value, double price) {
    bool is_added = false;
    for (int i = 0; i < import_food_resources.size(); i++) {
        if (value >= import_food_resources[i].max_value) {
            import_food_resources.insert(import_food_resources.cbegin() + i,
                                         {name, value, price, parameters.food_resources_nutritional_value[name]});
            is_added = true;
            break;
        }
    }
    if (!is_added) {
        import_food_resources.push_back({name, value, price, parameters.food_resources_nutritional_value[name]});
    }
}

void AnalyzingData::addMainBiome(string name, double square) {
    bool is_added = false;
    for (int i = 0; i < main_biomes.size(); i++) {
        if (square >= main_biomes[i].square) {
            main_biomes.insert(main_biomes.cbegin() + i, {name, square});
            is_added = true;
            break;
        }
    }
    if (!is_added) {
        main_biomes.push_back({name, square});
    }
}

void AnalyzingData::addAdditionalBiome(string name) {
    additional_biomes.push_back({name});
}
