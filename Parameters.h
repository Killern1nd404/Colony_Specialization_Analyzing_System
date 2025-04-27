#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <map>
#include <string>
#include <vector>

using namespace std;

// Структура ресурса
struct Resource {
    string name;
    double max_value;

    Resource(string name, double value) : name(name), max_value(value) {};
};

// Структура пищевого ресурса
struct FoodResource : public Resource {
    double nutritional_value;

    FoodResource(string name, double value, double nutritional_value) : Resource(name, value), nutritional_value(nutritional_value) {};
};

// Структура дополнительного биома
struct AdditionalBiome {
    string name;

    AdditionalBiome(string name) : name(name) {};
};

// Структура основного биома
struct Biome {
    string name;
    double square;

    Biome(string name, double square) : name(name), square(square) {};
};

// Структура необходимых ресорсов для развития инфраструктуры
struct ResourcesRequirements {
    double stone;
    double wood;
    double clay;
    double coal;
    double iron;

    ResourcesRequirements(double stone, double wood, double clay, double coal, double iron) : stone(stone), wood(wood), clay(clay),
        coal(coal), iron(iron) {};
    /*double getStone() {return stone;};
    double getWood() {return wood;};
    double getClay() {return clay;};
    double getCoal() {return coal;};
    double getIron() {return iron;};*/
};

// Структура опитмального биома с его типом, площадью и необходимыми ресурсами
struct OptimalBiome : public Biome, public ResourcesRequirements {
    //string biome;
    //string square;

    OptimalBiome(ResourcesRequirements data, string biome, double square) : Biome(biome, square),
        ResourcesRequirements(data.stone, data.wood, data.clay, data.coal, data.iron) {};
};

// Структура основных параметров
struct Parameters {
    // Возможные требования для развития инфраструктуры в биомах
    map<string, vector<ResourcesRequirements>> biomes_requirements = {
        {"PLAIN", {{10, 3, 2, 0, 1}, {8, 2, 2, 0, 3}, {2, 4, 8, 0, 2}}},
        {"HILLS", {{12, 4, 3, 0, 1}, {9, 3, 3, 0, 3}, {3, 5, 9, 0, 2}}},
        {"MOUNTAINS", {{10, 18, 0, 0, 6}, {4, 18, 8, 0, 6}}},
        {"SWAMP", {{10, 15, 0, 0, 4}, {4, 18, 6, 0, 4}}},
        {"FOREST", {{10, 3, 2, 0, 2}, {8, 2, 2, 0, 4}, {2, 4, 8, 0, 3}}}
    };
    // Параметры питательности пищевых продуктов
    map<string, double> food_resources_nutritional_value = {
        {"FRUIT", 0.75},
        {"SEED", 1.2},
        {"FISH", 1.5},
        {"MEAT", 1.5}
    };

    //Parameters() {};
};

/*map<string, double> food_resources_nutritional_value = {
    {"FRUIT", 0.75},
    {"SEED", 1.2},
    {"FISH", 1.5},
    {"MEAT", 1.5}
};*/

//#define Parameters PARAMETERS;

#endif // PARAMETERS_H
