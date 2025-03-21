#include "../headers/menu.h"
#include <iostream>
#include "../headers/inputValidator.h"

void Menu::show() {
    std::cout << "Menu: \n" <<
                     ADD_FIGURE << ".) Add figure to collection\n" <<
                     OUTPUT_PARAM << ".) Output a numbered list of figures with the shape type and its parameters\n" <<
                     OUTPUT_PERIM << ".) Output a numbered list of figures with the shape type and its perimeter\n" <<
                     PRINT_PERIM_SUM << ".) Print the sum of the perimeters of all figures\n" <<
                     SORT_PERIM_ASC << ".) Sort the figures in the collection in ascending order of perimeters\n" <<
                     DELETE_BY_NUM << ".) Delete a figure from the collection by its number\n" <<
                     DELETE_LARGER_PERIM << ".) Delete figures whose perimeters are larger than the entered value\n\n" <<
                     EXIT << " - close app\n\n" << std::endl;
    handlePollingInput();
}

void Menu::handleInput() {
    while (true) {
        InputValidator::getInput<int>("Enter: ", &inpValue);
        if (InputValidator::isError == false) break;
    }
    switch (inpValue) {
        case ADD_FIGURE: fManager.addFigure(); break;
        case OUTPUT_PARAM: fManager.printFigures(); break;
        case OUTPUT_PERIM: fManager.printFiguresPerimeters(); break;
        case PRINT_PERIM_SUM: fManager.printPerimetersSum(); break;
        case SORT_PERIM_ASC: fManager.sortFigures(); break;
        case DELETE_BY_NUM: fManager.deleteFigureByNumber(); break;
        case DELETE_LARGER_PERIM: fManager.deleteFiguresByPerimeter(); break;
        case EXIT: break;
        default: std::cout << "Your number isn't in action list"; break;
    };
}

void Menu::handlePollingInput() {
    while (inpValue != EXIT) {
        handleInput();
    }
}
