#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QMouseEvent>
#include <QTimer>
#include "basemouse.h"
#include "level3mouse.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool event(QEvent *event) override;

private slots:
    void updateGame();

private:
    Ui::MainWindow *ui;
    bool gameover = false;

    int currentLevel;
    BaseMouse* mouse;

    QTimer* m_gameTimer;
    QPoint m_cursorPos;

    void startGame();
    void nextLevel();
    void checkCollisions();
    void winLevel();
    void loseGame();
};
#endif // MAINWINDOW_H
