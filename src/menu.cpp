#include "../headers/menu.h"
#include <iostream>
#include "../headers/inputValidator.h"

void Menu::show() {
    for (const auto& pair : fManager.actionMap) {
        std::cout << pair.first << ".) " << pair.second.first << std::endl;
    }
    std::cout << EXIT << ".) Exit" << std::endl;
    handlePollingInput();
}

void Menu::handleInput() {
    while (true) {
        InputValidator::getInput<int>("Enter: ", &inpValue);
        if (InputValidator::isError == false) break;
    }
    if (inpValue != EXIT) {
        auto it = fManager.actionMap.find(inpValue);
        if (it != fManager.actionMap.end()) it->second.second();
        else std::cout << "There is no such key" << std::endl;
    }
}

void Menu::handlePollingInput() {
    while (inpValue != EXIT) {
        handleInput();
    }
}
