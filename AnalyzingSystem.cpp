#include "AnalyzingSystem.h"
#include "./ui_AnalyzingSystem.h"

AnalyzingSystem::AnalyzingSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AnalyzingSystem)
{
    ui->setupUi(this);
}

AnalyzingSystem::~AnalyzingSystem()
{
    delete ui;
}
