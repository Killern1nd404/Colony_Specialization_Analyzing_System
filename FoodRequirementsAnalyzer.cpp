#include "FoodRequirementsAnalyzer.h"
#include "Parameters.h"
#include <string>

void FoodRequirementsAnalyzer::writeDataInPlan() {
    if (max_potential > 0) {
        plan->addMakingResourceValue(food, max_potential);
    }
    if (total_price > 0) {
        plan->addImportingResourceValue(food, total_price);
    }
}

void FoodRequirementsAnalyzer::operator()() {
    double general_required_nutritional = data->getHumanNumber() * data->getRequiredNutritionalPerPerson() / 1000;
    for (FoodResource &making_food : data->getMakingFoodResources()) {
        for (ImportFoodResource &importing_food : data->getImportingFoodResources()) {
            if (importing_food.name == making_food.name) {
                double min_required_amount = general_required_nutritional / making_food.nutritional_value;
                if (min_required_amount <= making_food.max_value + importing_food.max_value) {
                    if (min_required_amount <= making_food.max_value) {
                        double min_required_operation_capacity = min_required_amount / (making_food.max_value);
                        if (max_potential < 0 || min_required_operation_capacity <= max_potential) {
                            max_potential = min_required_operation_capacity;
                            food = making_food.name;
                            total_price = 0;
                        }
                    } else {
                        for (int j = 5; j >= 0; j--) {
                            double making_food_amount = making_food.max_value*((double)j/10);
                            double importing_food_amount = min_required_amount - making_food_amount;
                            if (importing_food_amount <= importing_food.max_value && importing_food.price*importing_food_amount <= data->getMoney()) {
                                if (max_potential < 0 || ((double)j/10) < max_potential) {
                                    max_potential = ((double)j/10);
                                    food = making_food.name;
                                    total_price = importing_food.price*importing_food_amount;
                                    break;
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    if (food == "NONE") {
        throw CanNotCalculateFoodRequirements();
    }
    writeDataInPlan();
}
