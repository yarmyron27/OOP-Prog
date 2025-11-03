#include "basemouse.h"
#include <QDebug>

BaseMouse::BaseMouse(QLabel* jerry_label, int speed)
    : QObject(jerry_label->parentWidget()),
    jerry(jerry_label),
    speed(speed)
{

}

BaseMouse::~BaseMouse()
{

}

void BaseMouse::calculateMove(QPoint player_cursor_pos, QPoint hole_pos)
{
    Q_UNUSED(hole_pos);

    QPoint this_position = jerry->pos();

    int dx = this_position.x() - player_cursor_pos.x();
    int dy = this_position.y() - player_cursor_pos.y();

    double distance = std::sqrt(dx*dx + dy*dy);

    if (distance < 100) {
        double move_dx = 0;
        double move_dy = 0;

        if (distance > 0) {
            move_dx = (dx / distance) * speed;
            move_dy = (dy / distance) * speed;
        }

        int newX = this_position.x() + static_cast<int>(move_dx);
        int newY = this_position.y() + static_cast<int>(move_dy);

        move(QPoint(newX, newY), static_cast<QWidget*>(parent()));
    }
}

void BaseMouse::move(QPoint new_pos, QWidget* parent) {
    if (!parent) return;

    int newX = new_pos.x();
    int newY = new_pos.y();

    if (newX < 0) newX = 0;
    if (newY < 0) newY = 0;
    if (newX > parent->width() - jerry->width()) newX = parent->width() - jerry->width();
    if (newY > parent->height() - jerry->height()) newY = parent->height() - jerry->height();

    jerry->move(newX, newY);
}

QRect BaseMouse::geometry() {
    return jerry->geometry();
}

QPoint BaseMouse::pos() {
    return jerry->pos();
}

void BaseMouse::show() {
    jerry->show();
}

void BaseMouse::hide() {
    jerry->hide();
}
