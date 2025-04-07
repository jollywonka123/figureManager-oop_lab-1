#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <iostream>
#include <string>
#include <limits>
#include <memory>

class InputValidator {
public:
    static bool isError;

    template <typename ... Args>
    static void getInput(const std::string& prompt, Args*... args) {
        isError = false;
        std::cout << prompt;
        ((std::cin >> *args), ...);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect input, please try again." << std::endl;
            isError = true;
        }
    }
};

#endif //INPUTVALIDATOR_H
