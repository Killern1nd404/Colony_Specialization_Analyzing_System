#include "FinalPlan.h"
#include "Parameters.h"
#include <string>
#include <iostream>

using namespace std;

void FinalPlan::fillResources() {
    Parameters parameters;
    for (string &resource : parameters.resources_types) {
        making_resources[resource] = 0;
        importing_resources[resource] = 0;
    }
}

void FinalPlan::addMakingResourceValue(string resource, double value) {
    making_resources[resource] += value;
    total_operation_capacity += value;
}

void FinalPlan::addImportingResourceValue(string resource, double value) {
    importing_resources[resource] += value;
    total_price += value;
}

void FinalPlan::print() {
    cout << optimal_biome.name << endl;
    cout << total_price << endl;
    cout << total_operation_capacity << endl;
}
