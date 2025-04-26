#include "AnalyzingData.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

AnalyzingData::AnalyzingData() {
}

/*
    vector<string> make_production_resources_names;
    vector<double> make_production_resources_values;
    vector<string> make_food_resources_names;
    vector<double> make_food_resources_values;
    vector<string> import_production_resources_names;
    vector<double> import_production_resources_values;
    vector<string> import_food_resources_names;
    vector<double> import_food_resources_values;
    vector<string> main_biomes_names;
    vector<double> main_biomes_squares;
    vector<string> additional_biomes_names;
*/

/*
    AnalyzingData();
    void addMakingProductionResource(string name, double value);
    void addMakingFoodResource(string name, double value);
    void addImportingProductionResource(string name, double value);
    void addImportingFoodResource(string name, double value);
    void addMainBiome(string name, double square);
    void addAdditionalBiome(string name);
    void clearData();

    void checkData();
*/

void AnalyzingData::clearData() {
    if (!make_production_resources_names.empty()) {
        make_production_resources_names.clear();
        make_production_resources_values.clear();
        import_production_resources_names.clear();
        import_production_resources_values.clear();
        make_food_resources_names.clear();
        make_food_resources_values.clear();
        import_food_resources_names.clear();
        import_food_resources_values.clear();
        main_biomes_names.clear();
        main_biomes_squares.clear();
        additional_biomes_names.clear();
    }
}

void AnalyzingData::addMakingProductionResource(string name, double value) {
    bool is_added = false;
    for (int i = 0; i < make_production_resources_names.size(); i++) {
        if (value >= make_production_resources_values[i]) {
            make_production_resources_values.insert(make_production_resources_values.cbegin() + i, value);
            make_production_resources_names.insert(make_production_resources_names.cbegin() + i, name);
            is_added = true;
            break;
        }
    }
    if (!is_added) {
        make_production_resources_values.push_back(value);
        make_production_resources_names.push_back(name);
    }
}

void AnalyzingData::addMakingFoodResource(string name, double value) {
    bool is_added = false;
    for (int i = 0; i < make_food_resources_names.size(); i++) {
        if (value >= make_food_resources_values[i]) {
            make_food_resources_values.insert(make_food_resources_values.cbegin() + i, value);
            make_food_resources_names.insert(make_food_resources_names.cbegin() + i, name);
            is_added = true;
            break;
        }
    }
    if (!is_added) {
        make_food_resources_values.push_back(value);
        make_food_resources_names.push_back(name);
    }
}

void AnalyzingData::addImportingProductionResource(string name, double value) {
    bool is_added = false;
    for (int i = 0; i < import_production_resources_names.size(); i++) {
        if (value >= import_production_resources_values[i]) {
            import_production_resources_values.insert(import_production_resources_values.cbegin() + i, value);
            import_production_resources_names.insert(import_production_resources_names.cbegin() + i, name);
            is_added = true;
            break;
        }
    }
    if (!is_added) {
        import_production_resources_values.push_back(value);
        import_production_resources_names.push_back(name);
    }
}

void AnalyzingData::addImportingFoodResource(string name, double value) {
    bool is_added = false;
    for (int i = 0; i < import_food_resources_names.size(); i++) {
        if (value >= import_food_resources_values[i]) {
            import_food_resources_values.insert(import_food_resources_values.cbegin() + i, value);
            import_food_resources_names.insert(import_food_resources_names.cbegin() + i, name);
            is_added = true;
            break;
        }
    }
    if (!is_added) {
        import_food_resources_values.push_back(value);
        import_food_resources_names.push_back(name);
    }
}

void AnalyzingData::addMainBiome(string name, double square) {
    bool is_added = false;
    for (int i = 0; i < main_biomes_names.size(); i++) {
        if (square >= main_biomes_squares[i]) {
            main_biomes_squares.insert(main_biomes_squares.cbegin() + i, square);
            main_biomes_names.insert(main_biomes_names.cbegin() + i, name);
            is_added = true;
            break;
        }
    }
    if (!is_added) {
        main_biomes_squares.push_back(square);
        main_biomes_names.push_back(name);
    }
}

void AnalyzingData::addAdditionalBiome(string name) {
    additional_biomes_names.push_back(name);
}

/*void AnalyzingData::filterData() {
    filterMainBiomes();
}

void AnalyzingData::filterMainBiomes() {
    for (int i = main_biomes_names.size() - 1; i >= 0; i--) {
        if (main_biomes_squares[i] < 5) {
            main_biomes_squares.erase(main_biomes_squares.cbegin() + i);
            main_biomes_names.erase(main_biomes_names.cbegin() + i);
        }
    }
}

void AnalyzingData::filterMakeProductionResources() {

}*/

/*void AnalyzingData::checkData() {
    cout << "Make product resources:" << endl;
    for (int i = 0; i < make_production_resources_names.size(); i++) {
        cout << make_production_resources_names[i] << ": " << make_production_resources_values[i] << endl;
    }
    cout << endl;

    cout << "Make food resources:" << endl;
    for (int i = 0; i < make_food_resources_names.size(); i++) {
        cout << make_food_resources_names[i] << ": " << make_food_resources_values[i] << endl;
    }
    cout << endl;

    cout << "Import product resources:" << endl;
    for (int i = 0; i < import_production_resources_names.size(); i++) {
        cout << import_production_resources_names[i] << ": " << import_production_resources_values[i] << endl;
    }
    cout << endl;

    cout << "Import food resources:" << endl;
    for (int i = 0; i < import_food_resources_names.size(); i++) {
        cout << import_food_resources_names[i] << ": " << import_food_resources_values[i] << endl;
    }
    cout << endl;

    cout << "Main biomes" << endl;
    for (int i = 0; i < main_biomes_names.size(); i++) {
        cout << main_biomes_names[i] << ": " << main_biomes_squares[i] << endl;
    }
    cout << endl;

    cout << "Additional biomes:";
    for (string i : additional_biomes_names) {
        cout << i << endl;
    }
    cout << endl;
}*/
