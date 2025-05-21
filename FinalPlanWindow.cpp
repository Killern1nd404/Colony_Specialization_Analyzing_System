#include "FinalPlanWindow.h"
#include "ui_FinalPlanWindow.h"

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
