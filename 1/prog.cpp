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
std::vector<std::string> base_setup(int* arr_capacity) {
    std::ifstream in("base.txt");
    std::vector<std::string> base;
    std::string city;
    while (getline(in, city)) {
        (*arr_capacity)++;
        base.push_back(city);
    }
    in.close();
    return base;
}

// ввод использованного города
bool city_in(std::vector<std::string>& vec, const std::vector<std::string>& base) {
    std::string city;
    std::cout << PROMPT_CITY_INPUT;
    city = string_read();
    if (city_name_check(city, vec, base)) {
        vec.push_back(city);
        return true;
    }
    else {
        std::cout << PROMPT_ERR_INPUT << std::endl;
        return false;
    }
}

bool city_in(const char **used, int &length, const std::vector<std::string>& base) {
    std::cout << PROMPT_CITY_INPUT;
    std::string temp = string_read();
    if (city_name_check(temp, used, length, base)) {
        used[length] = new char[temp.size() + 1];
        strncpy((char*)used[length], temp.c_str(), temp.size() + 1);
        length++;
        return true;
    }
    else {
        std::cout << PROMPT_ERR_INPUT << std::endl;
        return false;
    }
}

// проверка правильности названия города
bool city_name_check(const std::string& city, const char** used, const int length, const std::vector<std::string>& base) {
    const std::string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ- ";
    return std::find(base.begin(), base.end(), city) != base.end()
        && std::all_of(city.begin(), city.end(), [&alph](char ch) {return std::find(alph.begin(), alph.end(), ch) != alph.end(); })
        && !is_in_array(used, length, city.c_str()) 
        && (length == 0 ? 1 : city[0] == toupper(last_letter(used[length - 1])));
}

bool city_name_check(const std::string& city, const std::vector<std::string>& vec, const std::vector<std::string>& base) {
    const std::string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ- ";
    return std::find(base.begin(), base.end(), city) != base.end()
        && std::find(vec.begin(), vec.end(), city) == vec.end() && (vec.empty() ? 1 : city[0] == toupper(last_letter(vec.back())))
        && std::all_of(city.begin(), city.end(), [&alph](char ch) {return std::find(alph.begin(), alph.end(), ch) != alph.end(); });
}

// основa
std::string answer(std::vector<std::string>& used, const std::vector<std::string>& base) {
    if (used.size() == 0)
        throw std::runtime_error(PROMPT_EMPTY_LIST);
    auto result = std::find_if(base.begin(), base.end(), [&used](std::string city)
        {return (find(used.begin(), used.end(), city) == used.end() && toupper(last_letter(used.back())) == city[0]); });
    if (result != base.end()) {
        used.push_back(base[result - base.begin()]);
        return base[result - base.begin()];
    }
    throw std::runtime_error(PROMPT_NO_ANSWER);
}

const char* answer(const char** used, int &length, const std::vector<std::string>& base) {
    if (length == 0)
        throw std::runtime_error(PROMPT_EMPTY_LIST);
    for (std::string city : base) {
        if (!is_in_array(used, length, city.c_str()) && city[0] == toupper(last_letter(used[length - 1]))) {
            used[length] = new char[city.size() + 1];
            strcpy_s((char*)used[length], (rsize_t)city.size() + 1, city.c_str());
            length++;
            return used[length - 1];
        }
    }
    throw std::runtime_error(PROMPT_NO_ANSWER);
}

// find для const char ** 
bool is_in_array(const char** arr, const int length, const char* str) {
    for (int i = 0; i < length; ++i)
        if (strcmp(arr[i], str) == 0)
            return true;
    return false;

}

// определение последней буквы
char last_letter(const std::string& city) {
    return last_letter(city.c_str());
}

char last_letter(const char* city) {
    const std::string forbidden = "hjqwx\0";
    //std::string_view sv(city);
    //size_t last = sv.find_last_not_of(forbidden);
    //return last != sv.npos ? city[last] : '\0';

    for (size_t i = strlen(city) - 1; i >= 0; --i)
        if (forbidden.find(city[i]) == std::string::npos)
            return city[i];
    return '\0';
}
