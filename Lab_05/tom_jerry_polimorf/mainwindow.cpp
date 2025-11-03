#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <cmath>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mouse(nullptr)
{
    ui->setupUi(this);

    this->setMouseTracking(true);

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

    ui->Tom->move(this->width() - ui->Tom->width() - 20, this->height() - ui->Tom->height() - 20);

    ui->hole->setFixedSize(80, 80);
    ui->hole->setStyleSheet("background-color: black; border-radius: 40px;");
    ui->hole->raise();
    ui->hole->hide();

    m_cursorPos = QPoint(0, 0);
    m_gameTimer = new QTimer(this);
    connect(m_gameTimer, &QTimer::timeout, this, &MainWindow::updateGame);

    startGame();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mouse;
}

void MainWindow::startGame()
{
    gameover = false;
    currentLevel = 0;
    nextLevel();
}

void MainWindow::nextLevel()
{
    currentLevel++;

    if (mouse) {
        delete mouse;
        mouse = nullptr;
    }

    m_gameTimer->stop();

    if (currentLevel == 1)
    {
        QMessageBox::information(this, "Новий рівень!", "Рівень 1");
        ui->hole->hide();
        mouse = new BaseMouse(ui->jerry, 10);
        ui->jerry->move(20, 20);
        ui->jerry->show();
        m_gameTimer->start(30);
    }
    else if (currentLevel == 2)
    {
        QMessageBox::information(this, "Новий рівень!", "Рівень 2");
        ui->hole->move(this->width() - ui->hole->width() - 20, 20);
        ui->hole->show();
        mouse = new Level2Mouse(ui->jerry, 6);
        ui->jerry->move(20, 20);
        ui->jerry->show();
        m_gameTimer->start(30);
    }
    else if (currentLevel == 3)
    {
        QMessageBox::information(this, "Новий рівень!", "Рівень 3");
        ui->hole->move(this->width() - ui->hole->width() - 20, 20);
        ui->hole->show();
        mouse = new Level3Mouse(ui->jerry, 9);
        ui->jerry->move(20, 20);
        ui->jerry->show();
        m_gameTimer->start(30);
    }
    else
    {
        gameover = true;
        m_gameTimer->stop();
        this->setMouseTracking(false);
        QMessageBox::information(this, "Перемога!", "Ви успішно загнали всіх мишей!");
        if (ui->jerry) ui->jerry->hide();
        if (mouse) {
            delete mouse;
            mouse = nullptr;
        }
    }
}

bool MainWindow::event(QEvent *event) {
    if (!gameover && event->type() == QEvent::MouseMove){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        m_cursorPos = mouseEvent->pos();
        return true;
    }
    return QMainWindow::event(event);
}

void MainWindow::updateGame()
{
    if (gameover || !mouse) return;

    QPoint holeCenter = ui->hole->pos() + QPoint(ui->hole->width()/2, ui->hole->height()/2);

    if (currentLevel == 1)
    {
        mouse->calculateMove(m_cursorPos, holeCenter);
    }
    else if (currentLevel >= 2)
    {
        mouse->calculateMove(m_cursorPos, holeCenter);
    }
    checkCollisions();
}

void MainWindow::checkCollisions()
{
    if (!mouse || gameover || !ui->jerry->isVisible()) return;

    if (mouse->geometry().intersects(ui->Tom->geometry())) {
        m_gameTimer->stop();
        winLevel();
    }
    else if (currentLevel >= 2 && ui->hole->isVisible() &&
             mouse->geometry().intersects(ui->hole->geometry()))
    {
        m_gameTimer->stop();
        loseGame();
    }
}

void MainWindow::winLevel()
{
    QMessageBox::information(this, "Чудово!", "Том зловив Джері!");
    gameover = false;
    nextLevel();
}

void MainWindow::loseGame()
{
    gameover = true;
    QMessageBox::warning(this, "Поразка!", "Джері втік у нору! Гра починається спочатку.");
    startGame();
}

