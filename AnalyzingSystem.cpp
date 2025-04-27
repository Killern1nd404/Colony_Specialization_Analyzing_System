#include "AnalyzingSystem.h"
#include "./ui_AnalyzingSystem.h"
#include <QTableWidgetItem>
#include "LanshaftAnalyzer.h"
#include <iostream>
#include <map>
#include "Parameters.h"

using namespace std;

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

    /*data.addMakingProductionResource("STONE", ui->make_stone_input->value());
    data.addMakingProductionResource("WOOD", ui->make_wood_input->value());
    data.addMakingProductionResource("CLAY", ui->make_clay_input->value());
    data.addMakingProductionResource("IRON", ui->make_iron_input->value());
    data.addMakingProductionResource("COAL", ui->make_coal_input->value());

    data.addMakingFoodResource("FRUIT", ui->make_fruit_input->value());
    data.addMakingFoodResource("FISH", ui->make_fish_input->value());
    data.addMakingFoodResource("SEED", ui->make_seed_input->value());
    data.addMakingFoodResource("MEAT", ui->make_meat_input->value());

    data.addImportingProductionResource("STONE", ui->import_stone_input->value());
    data.addImportingProductionResource("WOOD", ui->import_wood_input->value());
    data.addImportingProductionResource("CLAY", ui->import_clay_input->value());
    data.addImportingProductionResource("IRON", ui->import_iron_input->value());
    data.addImportingProductionResource("COAL", ui->import_coal_input->value());

    data.addImportingFoodResource("FRUIT", ui->import_fruit_input->value());
    data.addImportingFoodResource("FISH", ui->import_fish_input->value());
    data.addImportingFoodResource("SEED", ui->import_seed_input->value());
    data.addImportingFoodResource("MEAT", ui->import_meat_input->value());*/

    data.addMakingProductionResource("STONE", 205);
    data.addMakingProductionResource("WOOD", 316);
    data.addMakingProductionResource("CLAY", 124);
    data.addMakingProductionResource("IRON", 112);
    data.addMakingProductionResource("COAL", 106);

    data.addMakingFoodResource("FRUIT", ui->make_fruit_input->value());
    data.addMakingFoodResource("FISH", ui->make_fish_input->value());
    data.addMakingFoodResource("SEED", ui->make_seed_input->value());
    data.addMakingFoodResource("MEAT", ui->make_meat_input->value());

    data.addImportingProductionResource("STONE", ui->import_stone_input->value());
    data.addImportingProductionResource("WOOD", ui->import_wood_input->value());
    data.addImportingProductionResource("CLAY", ui->import_clay_input->value());
    data.addImportingProductionResource("IRON", ui->import_iron_input->value());
    data.addImportingProductionResource("COAL", ui->import_coal_input->value());

    data.addImportingFoodResource("FRUIT", ui->import_fruit_input->value());
    data.addImportingFoodResource("FISH", ui->import_fish_input->value());
    data.addImportingFoodResource("SEED", ui->import_seed_input->value());
    data.addImportingFoodResource("MEAT", ui->import_meat_input->value());

    /*for (int i = 0; i < ui->biomes_table->rowCount(); i++) {
        string square = ui->biomes_table->item(i, 1)->text().toStdString();
        square = square.replace(square.find(','), 1, ".");
        data.addMainBiome(ui->biomes_table->item(i, 0)->text().toStdString(), stod(square));
    }

    for (int i = 0; i < ui->additional_biomes_table->rowCount(); i++) {
        data.addAdditionalBiome(ui->additional_biomes_table->item(i, 0)->text().toStdString());
    }*/

    map<string, string> biomes_brinding = data.getBiomesBrinding();

    data.addMainBiome(biomes_brinding["Равнина"], 12.3);
    data.addMainBiome(biomes_brinding["Горы"], 4.3);
    data.addMainBiome(biomes_brinding["Лес"], 15.3);

    for (int i = 0; i < ui->additional_biomes_table->rowCount(); i++) {
        data.addAdditionalBiome(ui->additional_biomes_table->item(i, 0)->text().toStdString());
    }

    //data.filterData();

    //data.checkData();
}

void AnalyzingSystem::startAnalysis() {
    setAnalyzingData();

    LanshaftAnalyzer lanshaft_analyzer(&data);
    try {
        lanshaft_analyzer();
        OptimalBiome biome = data.getOptimalBiome();
        cout << biome.name << endl;
    } catch (SuitableBiomeNotFounded error) {
        cout << "Not nice biome Bebra" << endl;
    }
}
