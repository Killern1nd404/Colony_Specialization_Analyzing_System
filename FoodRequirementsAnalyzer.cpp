#include "FoodRequirementsAnalyzer.h"
#include "Parameters.h"
#include <string>
#include <iostream>

void FoodRequirementsAnalyzer::operator()() {
    double general_required_nutritional = data->getHumanNumber() * data->getRequiredNutritionalPerPerson() / 1000;
    //double max_potential = -1;
    //string food;
    //double total_price = 0;

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

    std::cout << food << ": " << max_potential << " " << total_price << std::endl;

    /*for (FoodResource &food : data->getMakingFoodResources()) {
        double min_required_amount = general_required_nutritional / food.nutritional_value;
        if (min_required_amount <= food.max_value) {
            double min_required_operation_capacity = min_required_amount / (food.max_value*1000);
            if (max_potential == 0 || min_required_operation_capacity < max_potential) {
                max_potential = min_required_operation_capacity;
                optimal_food = &food;
            }
        } else {
            for (ImportFoodResource &import_food : data->getImportingFoodResources()) {
                if (import_food.name == food.name) {
                    if (min_required_amount)
                }
            }
        }
        //double food_nutritional_potential = food.max_value * food.nutritional_value * 1000;
        //if (food_nutritional_potential > general_required_nutritional) {
        //
        //}
    }*/
}
