#ifndef LEVEL2MOUSE_H
#define LEVEL2MOUSE_H

#include "basemouse.h"

class Level2Mouse : public BaseMouse
{
    Q_OBJECT

public:
    Level2Mouse(QLabel* jerry_label, int speed);

    void calculateMove(QPoint player_cursor_pos, QPoint hole_pos) override;
};

#endif // LEVEL2MOUSE_H
