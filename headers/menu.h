#ifndef MENU_H
#define MENU_H

#include "figuresManager.h"

enum Option {
    EXIT,
    ADD_FIGURE,
    OUTPUT_PARAM,
    OUTPUT_PERIM,
    PRINT_PERIM_SUM,
    SORT_PERIM_ASC,
    DELETE_BY_NUM,
    DELETE_LARGER_PERIM,
};

class Menu {
    public:
    Menu(): fManager() {};
    void show();

    private:
    figuresManager fManager;
    int inpValue;
    void handleInput();
    void handlePollingInput();
};

class CreationMenu {};

#endif //MENU_H
