#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QList>
#include <QMessageBox>
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

public slots:
    void typechanged(int index);

private slots:
    void btn_addperson_cliced();
    void btn_deleteperson_cliced();

private:
    Ui::mainwindow *ui;
    QList<Person*> m_allPeople;
};
#endif // MAINWINDOW_H
