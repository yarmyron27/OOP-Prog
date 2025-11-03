#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "doctor.h"
#include "nurse.h"
#include "patient.h"

mainwindow::mainwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->setEnabled(false);

    connect(ui->typeHuman, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &mainwindow::typechanged);

    connect(ui->btn_addperson, &QPushButton::clicked, this, &mainwindow::btn_addperson_cliced);
    connect(ui->btn_deleteperson, &QPushButton::clicked, this, &mainwindow::btn_deleteperson_cliced);
}

mainwindow::~mainwindow()
{
    qDeleteAll(m_allPeople);
    delete ui;
}

void mainwindow::typechanged(int index) {
    if (index == 0) {
        ui->stackedWidget->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(0);
    }
    else {
        ui->stackedWidget->setEnabled(true);
        ui->stackedWidget->setCurrentIndex(index);
    }
}

void mainwindow::btn_addperson_cliced() {
    int index = ui->typeHuman->currentIndex();

    if (index == 0) {
        QMessageBox::warning(this, "Error!", "Please, enter type person");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Add this write?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::No) return;

    try {
        string name = ui->line_ed_name->text().toStdString();
        int age = ui->spin_age->value();

        Person* newPerson = nullptr;

        if (ui->typeHuman->currentIndex() == 1) {
            newPerson = new Doctor(name, age, ui->spin_experian->value(), ui->spin_operations->value());
        }
        else if (ui->typeHuman->currentIndex() == 2) {
            newPerson = new Nurse(name, age, ui->line_ed_qualif->text().toStdString(), ui->spin_procedures->value());
        }
        else if (ui->typeHuman->currentIndex() == 3) {
            newPerson = new Patient(name, age, ui->diagnosis_line_edit->text().toStdString());
        }

        if (newPerson) {
            m_allPeople.append(newPerson);
            ui->list_inf->addItem(newPerson->get_inf());
        }

        ui->line_ed_name->clear();
        ui->spin_age->setValue(0);

        ui->spin_experian->setValue(0);
        ui->spin_operations->setValue(0);

        ui->line_ed_qualif->clear();
        ui->spin_procedures->setValue(0);

        ui->diagnosis_line_edit->clear();

        ui->typeHuman->setCurrentIndex(0);

    } catch (const invalid_argument& e) {
        QMessageBox::critical(this, "Error, write data!", QString::fromStdString(e.what()));
    }
}

void mainwindow::btn_deleteperson_cliced()
{
    int currentRow = ui->list_inf->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "Error", "Pleace, select line for delete");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "You , Are you sure you want to delete this entry?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        delete m_allPeople[currentRow];
        m_allPeople.removeAt(currentRow);
        delete ui->list_inf->takeItem(currentRow);
    }
}
