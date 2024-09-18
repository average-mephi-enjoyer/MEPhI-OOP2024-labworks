#include <iostream>
#include <cstring>
#include <string>
#include "prog.h"
#include "inputs.h"
#include "prompts.h"

int main() {
    std::cout << PROMPT_INTRO << std::endl;
    std::cout << PROMPT_OVERLOAD_CHOICE;
    const char** used_arr = nullptr;
    int overload_choice, length = 0, arr_capacity = 0;
    try {
        std::vector<std::string> used_vec, base = base_setup(&arr_capacity);
        used_arr = new const char* [(size_t)arr_capacity];
        overload_choice = int_read(1, 2);
        std::cout << PROMPT_GAME_BEGIN << std::endl;
        if (overload_choice == 1) {
            while (1)
                if (city_in(used_arr, length, base))
                    std::cout << PROMPT_ANSWER << answer(used_arr, length, base) << std::endl;
        }
        else {
            while (1)
                if (city_in(used_vec, base))
                    std::cout << PROMPT_ANSWER << answer(used_vec, base) << std::endl;
        }
    }
    catch (std::bad_alloc& e) {
        std::cerr << e.what() << std::endl;
        for (int i = 0; i < length; ++i)
            delete[] used_arr[i];
        delete[] used_arr;
        return 1;
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        for (int i = 0; i < length; ++i)
            delete[] used_arr[i];
        delete[] used_arr;
        return 1;
    }
    return 0;
}