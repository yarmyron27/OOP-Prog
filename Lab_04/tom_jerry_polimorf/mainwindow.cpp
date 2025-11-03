#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <cmath>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMouseTracking(true);
    ui->jerry->setMouseTracking(true);
    ui->Tom->setMouseTracking(true);

    this->setStyleSheet("QMainWindow {"
                        "border-image: url(:/new/prefix1/TomandJerryTitle.jpg) 0 0 0 0 stretch stretch;"
                        "}");

    QPixmap jerryPixmap(":/new/prefix1/jerry.jpg");
    QPixmap tomPixmap(":/new/prefix1/Tom.jpg");

    ui->jerry->setPixmap(jerryPixmap);
    ui->Tom->setPixmap(tomPixmap);

    ui->jerry->setAttribute(Qt::WA_TranslucentBackground);
    ui->Tom->setAttribute(Qt::WA_TranslucentBackground);

    ui->jerry->setScaledContents(true);
    ui->Tom->setScaledContents(true);

    ui->jerry->setFixedSize(80, 60);
    ui->Tom->setFixedSize(150, 120);

    ui->jerry->raise();
    ui->Tom->raise();

    ui->jerry->move(20, 20);

    ui->Tom->move(this->width() - ui->Tom->width() - 20, this->height() - ui->Tom->height() - 20);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent *event) {
    if (!gameover && event->type() == QEvent::MouseMove){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        move_mouse(mouseEvent->pos());
        return true;
    }

    return QMainWindow::event(event);
}

void MainWindow::move_mouse(QPoint cursorPosition){
    QPoint thisPosition = ui->jerry->pos();

    int dx = thisPosition.x() - cursorPosition.x();
    int dy = thisPosition.y() - cursorPosition.y();

    double distance = std::sqrt(dx*dx + dy*dy);
    if (distance < 100) {
        int step = 5;

        int newX = thisPosition.x() + (dx / distance) * step;
        int newY = thisPosition.y() + (dy / distance) * step;

        if (newX < 0) newX = 0;
        if (newY < 0) newY = 0;
        if (newX > this->width() - ui->jerry->width()) newX = this->width() - ui->jerry->width();
        if (newY > this->height() - ui->jerry->height()) newY = this->height() - ui->jerry->height();

        ui->jerry->move(newX, newY);
        checkTrap();
    }
}

void MainWindow::checkTrap(){
    QRect jerry_rect = ui->jerry->geometry();
    QRect tom_rect = ui->Tom->geometry();

    if (jerry_rect.intersects(tom_rect)) {
        gameover = true;
        this->setMouseTracking(false);

        QMessageBox::information(this, "Гра закінчена!", "Том зловив Джжері!");
    }


}

