#ifndef ANALYZINGSYSTEM_H
#define ANALYZINGSYSTEM_H

#include <QMainWindow>
#include "AnalyzingData.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AnalyzingSystem;
}
QT_END_NAMESPACE

class AnalyzingSystem : public QMainWindow {
    Q_OBJECT
    AnalyzingData data;

public:
    AnalyzingSystem(QWidget *parent = nullptr);
    ~AnalyzingSystem();

private:
    Ui::AnalyzingSystem *ui;

private slots:
    void setAnalyzingData();
    void addBiome();
    void addAdditionalBiome();
    void startAnalysis();
};

#endif // ANALYZINGSYSTEM_H
