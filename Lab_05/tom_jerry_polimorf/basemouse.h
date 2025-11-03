#ifndef BASEMOUSE_H
#define BASEMOUSE_H

#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QPoint>
#include <QRect>
#include <cmath>

class BaseMouse : public QObject
{
    Q_OBJECT
public:
    BaseMouse(QLabel* jerry_label, int speed);
    virtual ~BaseMouse();

    virtual void calculateMove(QPoint player_cursor_pos, QPoint hole_pos);

    QRect geometry();
    QPoint pos();
    void show();
    void hide();

protected:
    QLabel* jerry;
    int speed;

    void move(QPoint new_pos, QWidget* parent);
};

#endif // BASEMOUSE_H
