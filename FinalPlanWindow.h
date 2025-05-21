#ifndef FINALPLANWINDOW_H
#define FINALPLANWINDOW_H

#include <QDialog>
#include "FinalPlan.h"

namespace Ui {
class FinalPlanWindow;
}

class FinalPlanWindow : public QDialog {
    Q_OBJECT
    Ui::FinalPlanWindow *ui;
    FinalPlan *final_plan;

public:
    explicit FinalPlanWindow(QWidget *parent = nullptr);
    void setFinalPlan(FinalPlan *plan) {final_plan = plan;};
    ~FinalPlanWindow();
};

#endif // FINALPLANWINDOW_H
