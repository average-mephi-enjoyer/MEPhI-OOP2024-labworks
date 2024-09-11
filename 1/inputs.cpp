#include <iostream>
#include "inputs.h"

template <typename T>
bool try_read(T& variable) {
    std::cin >> variable;
    if (std::cin.good())
        return true;
    if (std::cin.eof())
        throw std::runtime_error(PROMPT_EOF);
    if (std::cin.bad())
        throw std::runtime_error(PROMPT_BAD);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << PROMPT_FAIL;
        return false;
        //throw std::runtime_error(PROMPT_FAIL);
    }
    return true;
}

std::string string_read() {
    std::string res;
    while (!try_read(res));
    return res;
}

int int_read(int from, int to) {
    int integer_variable;
    while (1) {
        while (!try_read(integer_variable));
        if (from <= integer_variable && to >= integer_variable)
            return integer_variable;
        else std::cout << PROMPT_OUT_OF_RANGE;
    }
    return -1;
}
