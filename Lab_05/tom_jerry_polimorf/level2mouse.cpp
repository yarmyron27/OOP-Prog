#include "level2mouse.h"

Level2Mouse::Level2Mouse(QLabel* jerry_label, int speed)
    : BaseMouse(jerry_label, speed)
{

}

void Level2Mouse::calculateMove(QPoint player_cursor_pos, QPoint hole_pos)
{
    QPoint thisPosition = jerry->pos();

    int hole_dx = hole_pos.x() - thisPosition.x();
    int hole_dy = hole_pos.y() - thisPosition.y();
    double hole_distance = std::sqrt(hole_dx*hole_dx + hole_dy*hole_dy);

    double move_to_hole_x = 0;
    double move_to_hole_y = 0;
    if (hole_distance > 0) {
        move_to_hole_x = (hole_dx / hole_distance) * speed;
        move_to_hole_y = (hole_dy / hole_distance) * speed;
    }

    int cursor_dx = thisPosition.x() - player_cursor_pos.x();
    int cursor_dy = thisPosition.y() - player_cursor_pos.y();
    double cursor_distance = std::sqrt(cursor_dx*cursor_dx + cursor_dy*cursor_dy);

    double move_from_cursor_x = 0;
    double move_from_cursor_y = 0;

    const double repulsion_multiplier = 2.5;
    const double repulsion_speed = speed * repulsion_multiplier;

    if (cursor_distance < 150 && cursor_distance > 0) {
        move_from_cursor_x = (cursor_dx / cursor_distance) * repulsion_speed;
        move_from_cursor_y = (cursor_dy / cursor_distance) * repulsion_speed;
    }

    int newX = thisPosition.x() + static_cast<int>(move_to_hole_x + move_from_cursor_x);
    int newY = thisPosition.y() + static_cast<int>(move_to_hole_y + move_from_cursor_y);

    move(QPoint(newX, newY), static_cast<QWidget*>(parent()));
}
