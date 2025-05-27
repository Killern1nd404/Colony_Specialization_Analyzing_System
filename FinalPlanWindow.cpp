#include "FinalPlanWindow.h"
#include "ui_FinalPlanWindow.h"
#include "Parameters.h"
#include <QString>
#include <string>
#include <map>

FinalPlanWindow::FinalPlanWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FinalPlanWindow)
{
    ui->setupUi(this);
}

FinalPlanWindow::~FinalPlanWindow()
{
    delete ui;
}

void FinalPlanWindow::fillInfrastructureData() {
    OptimalBiome biome = final_plan.getOptimalBiome();
    Parameters parameters;

    ui->biome->setText(QString::fromStdString(parameters.biomes_brinding_to_rus[biome.name]));
    ui->square->setText(QString::fromStdString(std::to_string(biome.square)));
    ui->stone->setText(QString::fromStdString(std::to_string(biome.stone)));
    ui->wood->setText(QString::fromStdString(std::to_string(biome.wood)));
    ui->clay->setText(QString::fromStdString(std::to_string(biome.clay)));
    ui->iron->setText(QString::fromStdString(std::to_string(biome.iron)));
    ui->coal->setText(QString::fromStdString(std::to_string(biome.coal)));
}

void FinalPlanWindow::fillMakingData() {
    map<string, double> making_resources_data = final_plan.getMakingResources();

    ui->stone_make->setText(QString::fromStdString(std::to_string(making_resources_data["STONE"]*100)+" %"));
    ui->wood_make->setText(QString::fromStdString(std::to_string(making_resources_data["WOOD"]*100)+" %"));
    ui->clay_make->setText(QString::fromStdString(std::to_string(making_resources_data["CLAY"]*100)+" %"));
    ui->iron_make->setText(QString::fromStdString(std::to_string(making_resources_data["IRON"]*100)+" %"));
    ui->coal_make->setText(QString::fromStdString(std::to_string(making_resources_data["COAL"]*100)+" %"));
    ui->fruit_make->setText(QString::fromStdString(std::to_string(making_resources_data["FRUIT"]*100)+" %"));
    ui->fish_make->setText(QString::fromStdString(std::to_string(making_resources_data["FISH"]*100)+" %"));
    ui->seed_make->setText(QString::fromStdString(std::to_string(making_resources_data["SEED"]*100)+" %"));
    ui->meat_make->setText(QString::fromStdString(std::to_string(making_resources_data["MEAT"]*100)+" %"));
}

void FinalPlanWindow::fillImportingData() {
    map<string, double> importing_resources_data = final_plan.getImportingResources();

    ui->stone_import->setText(QString::fromStdString(std::to_string(importing_resources_data["STONE"])+" руб."));
    ui->wood_import->setText(QString::fromStdString(std::to_string(importing_resources_data["WOOD"])+" руб."));
    ui->clay_import->setText(QString::fromStdString(std::to_string(importing_resources_data["CLAY"])+" руб."));
    ui->iron_import->setText(QString::fromStdString(std::to_string(importing_resources_data["IRON"])+" руб."));
    ui->coal_import->setText(QString::fromStdString(std::to_string(importing_resources_data["COAL"])+" руб."));
    ui->fruit_import->setText(QString::fromStdString(std::to_string(importing_resources_data["FRUIT"])+" руб."));
    ui->fish_import->setText(QString::fromStdString(std::to_string(importing_resources_data["FISH"])+" руб."));
    ui->seed_import->setText(QString::fromStdString(std::to_string(importing_resources_data["SEED"])+" руб."));
    ui->meat_import->setText(QString::fromStdString(std::to_string(importing_resources_data["MEAT"])+" руб."));
    ui->total_price->setText(QString::fromStdString(std::to_string(final_plan.getTotalPrice())+" руб."));
}

void FinalPlanWindow::updateData() {
    fillInfrastructureData();
    fillMakingData();
    fillImportingData();
}
