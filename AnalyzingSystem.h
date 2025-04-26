#ifndef ANALYZINGSYSTEM_H
#define ANALYZINGSYSTEM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class AnalyzingSystem;
}
QT_END_NAMESPACE

class AnalyzingSystem : public QMainWindow
{
    Q_OBJECT

public:
    AnalyzingSystem(QWidget *parent = nullptr);
    ~AnalyzingSystem();

private:
    Ui::AnalyzingSystem *ui;
};
#endif // ANALYZINGSYSTEM_H
