#include "AnalyzingSystem.h"
#include "./ui_AnalyzingSystem.h"
#include <QTableWidgetItem>
#include "LanshaftAnalyzer.h"
#include <map>
#include "FoodRequirementsAnalyzer.h"
#include "FinalPlanWindow.h"

AnalyzingSystem::AnalyzingSystem(QWidget *parent) : QMainWindow(parent), ui(new Ui::AnalyzingSystem) {
    ui->setupUi(this);

    connect(ui->start_analysis_button, &QPushButton::clicked, this, &AnalyzingSystem::startAnalysis);
    connect(ui->add_biome_button, &QPushButton::clicked, this, &AnalyzingSystem::addBiome);
    connect(ui->add_additional_biome_button, &QPushButton::clicked, this, &AnalyzingSystem::addAdditionalBiome);
}

AnalyzingSystem::~AnalyzingSystem()
{
    delete ui;
}

void AnalyzingSystem::addBiome() {
    ui->biomes_table->insertRow(ui->biomes_table->rowCount());
    ui->biomes_table->setItem(ui->biomes_table->rowCount() - 1, 0, new QTableWidgetItem(ui->biome_input->currentText()));
    ui->biomes_table->setItem(ui->biomes_table->rowCount() - 1, 1, new QTableWidgetItem(ui->biome_square_input->text()));
}

void AnalyzingSystem::addAdditionalBiome() {
    ui->additional_biomes_table->insertRow(ui->additional_biomes_table->rowCount());
    ui->additional_biomes_table->setItem(ui->additional_biomes_table->rowCount() - 1, 0, new QTableWidgetItem(ui->additional_biome_input->currentText()));
}

void AnalyzingSystem::setAnalyzingData() {
    data.clearData();

    data.addMakingProductionResource("STONE", ui->make_stone_input->value());
    data.addMakingProductionResource("WOOD", ui->make_wood_input->value());
    data.addMakingProductionResource("CLAY", ui->make_clay_input->value());
    data.addMakingProductionResource("IRON", ui->make_iron_input->value());
    data.addMakingProductionResource("COAL", ui->make_coal_input->value());

    data.addMakingFoodResource("FRUIT", ui->make_fruit_input->value());
    data.addMakingFoodResource("FISH", ui->make_fish_input->value());
    data.addMakingFoodResource("SEED", ui->make_seed_input->value());
    data.addMakingFoodResource("MEAT", ui->make_meat_input->value());

    /*data.addMakingProductionResource("STONE", 56.43);
    data.addMakingProductionResource("WOOD", 103.4);
    data.addMakingProductionResource("CLAY", 1.5);
    data.addMakingProductionResource("IRON", 43);
    data.addMakingProductionResource("COAL", 15);

    data.addMakingFoodResource("FRUIT", 13);
    data.addMakingFoodResource("FISH", ui->make_fish_input->value());
    data.addMakingFoodResource("SEED", ui->make_seed_input->value());
    data.addMakingFoodResource("MEAT", ui->make_meat_input->value());*/



    data.addImportingProductionResource("STONE", ui->import_stone_input->value(), ui->import_price_stone_input->value());
    data.addImportingProductionResource("WOOD", ui->import_wood_input->value(), ui->import_price_wood_input->value());
    data.addImportingProductionResource("CLAY", ui->import_clay_input->value(), ui->import_price_clay_input->value());
    data.addImportingProductionResource("IRON", ui->import_iron_input->value(), ui->import_price_iron_input->value());
    data.addImportingProductionResource("COAL", ui->import_coal_input->value(), ui->import_price_coal_input->value());

    data.addImportingFoodResource("FRUIT", ui->import_fruit_input->value(), ui->import_price_fruit_input->value());
    data.addImportingFoodResource("FISH", ui->import_fish_input->value(), ui->import_price_fish_input->value());
    data.addImportingFoodResource("SEED", ui->import_seed_input->value(), ui->import_price_seed_input->value());
    data.addImportingFoodResource("MEAT", ui->import_meat_input->value(), ui->import_price_meat_input->value());

    /*data.addImportingProductionResource("STONE", 252, 1452);
    data.addImportingProductionResource("WOOD", 153, 2422);
    data.addImportingProductionResource("CLAY", 163, 1563);
    data.addImportingProductionResource("IRON", ui->import_iron_input->value(), ui->import_price_iron_input->value());
    data.addImportingProductionResource("COAL", 321, 522);

    data.addImportingFoodResource("FRUIT", ui->import_fruit_input->value(), ui->import_price_fruit_input->value());
    data.addImportingFoodResource("FISH", ui->import_fish_input->value(), ui->import_price_fish_input->value());
    data.addImportingFoodResource("SEED", ui->import_seed_input->value(), ui->import_price_seed_input->value());
    data.addImportingFoodResource("MEAT", ui->import_meat_input->value(), ui->import_price_meat_input->value());*/


    for (int i = 0; i < ui->biomes_table->rowCount(); i++) {
        string square = ui->biomes_table->item(i, 1)->text().toStdString();
        square = square.replace(square.find(','), 1, ".");
        data.addMainBiome(data.getBiomesBrinding()[ui->biomes_table->item(i, 0)->text().toStdString()], stod(square));
    }

    for (int i = 0; i < ui->additional_biomes_table->rowCount(); i++) {
        data.addAdditionalBiome(ui->additional_biomes_table->item(i, 0)->text().toStdString());
    }

    /*data.addMainBiome("PLAIN", 7);
    data.addMainBiome("HILLS", 15.31);
    data.addMainBiome("MOUNTAINS", 13.4);
    data.addAdditionalBiome("Река");*/



    map<string, string> biomes_brinding = data.getBiomesBrinding();

    data.setHumanNumber(ui->human_number_input->value());
    data.setMoney(ui->money_number_input->value());
    //data.setMoney(100000);
}

void AnalyzingSystem::startAnalysis() {
    setAnalyzingData();
    final_plan_builder.clearPlan();

    try {
        food_analyzer.setAnalyzingData(&data);
        food_analyzer.setPlanBuilder(&final_plan_builder);
        food_analyzer();
        lanshaft_analyzer.setAllData(&data, &final_plan_builder, data.getMoney() - food_analyzer.getTotalPrice(), 1 - food_analyzer.getOperationCapacity());
        lanshaft_analyzer();
        plan_window.setFinalPlan(final_plan_builder.returnPlan());
        plan_window.setModal(true);
        plan_window.updateData();
        plan_window.exec();
    } catch (SuitableBiomeNotFounded error) {
        ui->error_label->setText(QString::fromStdString("Не удалось найти подходящий биом"));
    } catch (CanNotCalculateFoodRequirements error) {
        ui->error_label->setText(QString::fromStdString("Не хватает доступной пищи"));
    } catch (DrinkWaterSourceNotFounded error) {
        ui->error_label->setText(QString::fromStdString("Не найдено источников питьевой воды"));
    }
}
