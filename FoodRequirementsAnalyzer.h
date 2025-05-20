#ifndef FOODREQUIREMENTSANALYZER_H
#define FOODREQUIREMENTSANALYZER_H

#include <vector>
#include "Parameters.h"
#include <map>
#include <string>
#include "AnalyzingData.h"

class FoodRequirementsAnalyzer {
    AnalyzingData *data;
    double max_potential = -1;
    string food;
    double total_price = 0;

public:
    FoodRequirementsAnalyzer(AnalyzingData *data) : data(data) {};
    void operator()();
    double getOperationCapacity() {return max_potential;};
    string getFoodName() {return food;};
    double getTotalPrice() {return total_price;};
};

#endif // FOODREQUIREMENTSANALYZER_H
