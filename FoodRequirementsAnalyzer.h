#ifndef FOODREQUIREMENTSANALYZER_H
#define FOODREQUIREMENTSANALYZER_H

#include <string>
#include "AnalyzingData.h"

class CanNotCalculateFoodRequirements {
public:
    CanNotCalculateFoodRequirements() {};
};

class FoodRequirementsAnalyzer {
    AnalyzingData *data;
    double max_potential = -1;
    string food = "NONE";
    double total_price = 0;

public:
    FoodRequirementsAnalyzer(AnalyzingData *data) : data(data) {};
    void operator()();
    double getOperationCapacity() {return max_potential;};
    string getFoodName() {return food;};
    double getTotalPrice() {return total_price;};
};

#endif // FOODREQUIREMENTSANALYZER_H
