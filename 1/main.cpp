#include <iostream>
#include <cstring>
#include <string>
#include "prog.h"
#include "inputs.h"
#include "prompts.h"

int main() {
    std::cout << PROMPT_000;
    std::cout << PROMPT_001;
    std::vector<std::string> base, in_cities;
    base_setup(base);

    int overload_choice;
    try {
        overload_choice = int_read(1, 2);
        cities_input(&in_cities, base);
        process(overload_choice, in_cities, base);
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch (std::logic_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
