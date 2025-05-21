#ifndef ANALYZINGDATA_H
#define ANALYZINGDATA_H

#include <vector>
#include <string>
#include "Parameters.h"

using namespace std;

class AnalyzingData {
    vector<Resource> make_production_resources;
    vector<FoodResource> make_food_resources;
    vector<ImportResource> import_production_resources;
    vector<ImportFoodResource> import_food_resources;
    vector<Biome> main_biomes;
    vector<AdditionalBiome> additional_biomes;
    Parameters parameters;
    int human_number;
    double money;

    OptimalBiome optimal_biome;
    double money_expenses;

public:
    AnalyzingData();
    void clearData();

    void addMakingProductionResource(string name, double value);
    void addMakingFoodResource(string name, double value);
    void addImportingProductionResource(string name, double value, double price);
    void addImportingFoodResource(string name, double value, double price);
    void addMainBiome(string name, double square);
    void addAdditionalBiome(string name);
    void setOptimalBiome(OptimalBiome biome) {optimal_biome=biome;};
    void setHumanNumber(int n) {human_number=n;};
    void setMoney(int n) {money=n;};

    vector<Biome> getMainBiomes() {return main_biomes;};
    vector<AdditionalBiome> getAdditionalBiomes() {return additional_biomes;};
    vector<Resource> getMakingProductionResources() {return make_production_resources;};
    vector<FoodResource> getMakingFoodResources() {return make_food_resources;};
    vector<ImportResource> getImportingProductionResources() {return import_production_resources;};
    vector<ImportFoodResource> getImportingFoodResources() {return import_food_resources;};
    map<string, vector<ResourcesRequirements>> getBiomesRequiremets() {return parameters.biomes_requirements;};
    map<string, string> getBiomesBrinding() {return parameters.biomes_brinding;};
    double getMinRequiredSquare() {return parameters.min_required_square;};
    OptimalBiome getOptimalBiome() {return optimal_biome;};
    int getHumanNumber() {return human_number;};
    double getMoney() {return money;};
    double getRequiredNutritionalPerPerson() {return parameters.required_nutritional_per_person;};
};

#endif // ANALYZINGDATA_H
