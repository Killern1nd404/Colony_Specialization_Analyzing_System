#ifndef ANALYZINGSYSTEM_H
#define ANALYZINGSYSTEM_H

#include <QMainWindow>
#include "AnalyzingData.h"
#include "FinalPlan.h"
#include "FoodRequirementsAnalyzer.h"
#include "LanshaftAnalyzer.h"
#include "FinalPlanWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AnalyzingSystem;
}
QT_END_NAMESPACE

class AnalyzingSystem : public QMainWindow {
    Q_OBJECT
    Ui::AnalyzingSystem *ui;
    AnalyzingData data;
    //FinalPlan final_plan;
    FinalPlanBuilder final_plan_builder;
    FoodRequirementsAnalyzer food_analyzer;
    LanshaftAnalyzer lanshaft_analyzer;
    FinalPlanWindow plan_window;

public:
    AnalyzingSystem(QWidget *parent = nullptr);
    ~AnalyzingSystem();

private slots:
    void setAnalyzingData();
    void addBiome();
    void addAdditionalBiome();
    void startAnalysis();
};

#endif // ANALYZINGSYSTEM_H
