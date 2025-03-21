#ifndef APP_H
#define APP_H

#include "menu.h"

class App {
    Menu menu;
    public:
    App(): menu() {}
    void start();
};



#endif //APP_H
