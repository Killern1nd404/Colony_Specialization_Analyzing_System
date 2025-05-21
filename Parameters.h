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
    FoodResource() : Resource("NONE", 0), nutritional_value(0) {};
};

struct ImportResource : public Resource {
    double price;

    ImportResource(string name, double value, double price) : Resource(name, value), price(price) {};
};

struct ImportFoodResource : public ImportResource {
    double nutritional_value;

    ImportFoodResource(string name, double value, double price, double nutritional_value) : ImportResource(name, value, price), nutritional_value(nutritional_value) {};
    ImportFoodResource() : ImportResource("NONE", 0, 0), nutritional_value(0) {};
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

    ResourcesRequirements(double stone, double wood, double clay, double iron, double coal) : stone(stone), wood(wood), clay(clay),
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

    OptimalBiome() : Biome("NONE", 0), ResourcesRequirements(0, 0, 0, 0, 0) {};
    OptimalBiome(ResourcesRequirements data, string biome, double square) : Biome(biome, square),
        ResourcesRequirements(data.stone, data.wood, data.clay, data.iron, data.coal) {};
    void setBiome(string name, double square, double stone, double wood, double clay, double iron, double coal) {
        this->name = name;
        this->square = square;
        this->stone = stone;
        this->wood = wood;
        this->clay = clay;
        this->iron = iron;
        this->coal = coal;
    };
    void operator=(OptimalBiome &other) {
        this->name = other.name;
        this->square = other.square;
        this->stone = other.stone;
        this->wood = other.wood;
        this->clay = other.clay;
        this->iron = other.iron;
        this->coal = other.coal;
    }
    /*void setBiome(OptimalBiome biome) {
        this->name = biome.name;
        this->square = biome.square;
        this->stone = biome.stone;
        this->wood = biome.wood;
        this->clay = biome.clay;
        this->iron = biome.iron;
        this->coal = biome.coal;
    };*/
};

// Структура основных параметров
struct Parameters {
    vector<string> resources_types = {"STONE", "WOOD", "CLAY", "IRON", "COAL", "FRUIT", "FISH", "SEED", "MEAT"};
    // Возможные требования для развития инфраструктуры в биомах
    map<string, vector<ResourcesRequirements>> biomes_requirements = {
        {"PLAIN", {{10, 3, 2, 1, 0}, {8, 2, 2, 3, 0}, {2, 4, 8, 2, 0}}},
        {"HILLS", {{12, 4, 3, 1, 0}, {9, 3, 3, 3, 0}, {3, 5, 9, 2, 0}}},
        {"MOUNTAINS", {{10, 18, 0, 6, 0}, {4, 18, 8, 6, 0}}},
        {"SWAMP", {{10, 15, 0, 4, 0}, {4, 18, 6, 4, 0}}},
        {"FOREST", {{10, 3, 2, 2, 0}, {8, 2, 2, 4, 0}, {2, 4, 8, 3, 0}}}
    };
    // Параметры питательности пищевых продуктов
    map<string, double> food_resources_nutritional_value = {
        {"FRUIT", 0.75},
        {"SEED", 1.2},
        {"FISH", 1.5},
        {"MEAT", 1.5}
    };
    // Приведение названий биомов
    map<string, string> biomes_brinding = {
        {"Равнина", "PLAIN"},
        {"Болото", "SWAMP"},
        {"Горы", "MOUNTAINS"},
        {"Холмы", "HILLS"},
        {"Лес", "FOREST"},
        {"Море/Океан", "SEA"},
        {"Река", "RIVER"},
        {"Озеро", "LAKE"}
    };
    // Приведение названий биомов
    map<string, string> biomes_brinding_to_rus = {
        {"PLAIN", "Равнина"},
        {"SWAMP", "Болото"},
        {"MOUNTAINS", "Горы"},
        {"HILLS", "Холмы"},
        {"FOREST", "Лес"},
        {"SEA", "Море/Океан"},
        {"RIVER", "Река"},
        {"LAKE", "Озеро"}
    };
    // Минимальное площадь биома для организации колонии
    double min_required_square = 5;
    double required_nutritional_per_person = 1;

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
