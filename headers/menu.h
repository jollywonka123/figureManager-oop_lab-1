#ifndef MENU_H
#define MENU_H

#include "figuresManager.h"
#include "optional"
#include "constants.h"

class Menu {
    public:
    Menu(): fManager(), inpValue(DEFAULT) {};
    void show();

private:
    FiguresManager fManager;
    int inpValue;
    void handleInput();
    void handlePollingInput();
};

class CreationMenu {};

#endif //MENU_H
