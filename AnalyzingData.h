#ifndef ANALYZINGDATA_H
#define ANALYZINGDATA_H

#include <vector>
#include <string>
#include "Parameters.h"

using namespace std;

class AnalyzingData {
    /*vector<string> make_production_resources_names;
    vector<double> make_production_resources_values;
    vector<string> make_food_resources_names;
    vector<double> make_food_resources_values;
    vector<string> import_production_resources_names;
    vector<double> import_production_resources_values;
    vector<string> import_food_resources_names;
    vector<double> import_food_resources_values;
    vector<string> main_biomes_names;
    vector<double> main_biomes_squares;
    vector<string> additional_biomes_names;*/

    vector<Resource> make_production_resources;
    vector<FoodResource> make_food_resources;
    vector<Resource> import_production_resources;
    vector<FoodResource> import_food_resources;
    vector<Biome> main_biomes;
    vector<AdditionalBiome> additional_biomes;

    Parameters parameters;

    /*void filterMakeProductionResources();
    void filterMakeFoodResources();
    void filterImportProductionResources();
    void filterImportFoodResources();
    void filterMainBiomes();*/


public:
    AnalyzingData();
    void addMakingProductionResource(string name, double value);
    void addMakingFoodResource(string name, double value);
    void addImportingProductionResource(string name, double value);
    void addImportingFoodResource(string name, double value);
    void addMainBiome(string name, double square);
    void addAdditionalBiome(string name);
    void clearData();
    //void filterData();
    //void filterMainBiomes();
    //vector<string> getMainBiomesNames() {return main_biomes_names;};
    //vector<double> getMainBiomesSquares() {return main_biomes_squares;};
    vector<Biome> getMainBiomes() {return main_biomes;};
    //map<string, double> getFoodNutritionalValue() {return parameters.food_resources_nutritional_value;};

    //void checkData();
};

#endif // ANALYZINGDATA_H
