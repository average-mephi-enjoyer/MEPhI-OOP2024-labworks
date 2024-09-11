#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
#include "prog.h"
#include "inputs.h"
#include "prompts.h"

// загрузка общего списка городов из файла
int base_setup(std::vector<std::string>& base) {
    std::ifstream in("C:\\Users\\artem\\source\\repos\\b23516_iashchenko.ai\\1\\base.txt");
    std::string city;
    while (getline(in, city))
        base.push_back(city);
    in.close();
    return 0;
}

// ввод использованных городов
int cities_input(std::vector<std::string>* vec, std::vector<std::string>& base) {
    try {
        while (1) {
            std::cout << PROMPT_002;
            std::string temp = string_read();
            if (!city_name_check(temp, base))
                std::cout << PROMPT_004 << std::endl;
            else {
                (*vec).push_back(temp);
                base.erase(find(base.begin(), base.end(), temp));
            }
        }
    }
    catch (std::runtime_error) {
        std::cout << PROMPT_003 << std::endl;
        return 1;
    }
    return 0;
}

// проверка правильности названия города
bool city_name_check(std::string& city, std::vector<std::string>& base) {
    if (find(base.begin(), base.end(), city) == base.end())
        return false;
    for (char c : city)
        if ((int)c < 45 || (int)c > 45 && (int)c < 65 || (int)c > 90 && (int)c < 97 || (int)c > 122)
            throw std::logic_error(PROMPT_005);
    return true;
}

// основа
int process(int& overload_choice, std::vector<std::string>& in_cities, std::vector<std::string>& base) {
    if (in_cities.size() == 0)
        throw std::runtime_error(PROMPT_006);
    if (overload_choice == 2)
        std::cout << get_answer(toupper(last_letter(in_cities.back())), base) << std::endl;
    else {
        char** arr = new char* [318];
        for (int i = 0; i < in_cities.size(); ++i) {
            arr[i] = new char[in_cities[i].size() + 1];
            strcpy_s(arr[i], (rsize_t)(in_cities[i].size() + 1), in_cities[i].c_str());
        }
        std::cout << get_answer(toupper(last_letter(in_cities[in_cities.size() - 1])), in_cities.size(), base) << std::endl;
        for (int i = 0; i < in_cities.size(); ++i)
            delete[] arr[i];
        delete[] arr;
    }
    return 0;
}

// нахождение ответа
std::string get_answer(char ch, std::vector<std::string>& base) {
    for (int i = 0; i < base.size(); ++i)
        if (base[i][0] == ch)
            return base[i];
    throw std::runtime_error(PROMPT_007);
}

const char* get_answer(char ch, int length, std::vector<std::string>& base) {
    for (int i = 0; i < base.size(); ++i)
        if (base[i][0] == ch)
            return base[i].c_str();
    throw std::runtime_error(PROMPT_007);
}

// определение последней буквы
char last_letter(std::string& city) {
    std::string forbidden = "hjqwx\0";
    for (int i = city.size() - 1; i >= 0; --i) {
        if (find(forbidden.begin(), forbidden.end(), city[i]) == forbidden.end())
            return city[i];
    }
    return '\0';
}

char last_letter(const char* city) {
    std::string forbidden = "hjqwx\0";
    std::cout << city << std::endl;
    for (int i = strlen(city) - 1; i >= 0; --i)
        if (find(forbidden.begin(), forbidden.end(), city[i]) == forbidden.end())
            return city[i];
    return '\0';
}
