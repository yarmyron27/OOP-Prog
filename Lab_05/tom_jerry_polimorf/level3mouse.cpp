#ifndef LEVEL3MOUSE_H
#define LEVEL3MOUSE_H

#include "level2mouse.h"

class Level3Mouse : public Level2Mouse
{
    Q_OBJECT
public:
    Level3Mouse(QLabel* jerry_label, int speed)
        : Level2Mouse(jerry_label, speed) {}
};

#endif // LEVEL3MOUSE_H
