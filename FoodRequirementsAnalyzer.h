#ifndef FOODREQUIREMENTSANALYZER_H
#define FOODREQUIREMENTSANALYZER_H

#include <string>
#include "AnalyzingData.h"
#include "FinalPlan.h"

class CanNotCalculateFoodRequirements {
public:
    CanNotCalculateFoodRequirements() {};
};

class FoodRequirementsAnalyzer {
    AnalyzingData *data;
    FinalPlanBuilder *plan_builder;
    double max_potential = -1;
    string food = "NONE";
    double total_price = 0;

    void writeDataInPlan();

public:
    FoodRequirementsAnalyzer() {};
    void setAnalyzingData(AnalyzingData *data_) {data=data_;};
    void setPlanBuilder(FinalPlanBuilder *builder) {plan_builder=builder;};
    void operator()();
    double getOperationCapacity() {return max_potential;};
    string getFoodName() {return food;};
    double getTotalPrice() {return total_price;};
};

#endif // FOODREQUIREMENTSANALYZER_H
