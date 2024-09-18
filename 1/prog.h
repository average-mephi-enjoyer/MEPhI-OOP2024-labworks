#ifndef PROG_H
#define PROG_H
#include <vector>

std::vector<std::string> base_setup(int *arr_capacity);

bool city_in(std::vector<std::string>& vec, const std::vector<std::string>& base);
bool city_in(const char** used, int* length, const std::vector<std::string>& base);
bool city_name_check(const std::string& city, const std::vector<std::string>& vec, const std::vector<std::string>& base);
bool city_name_check(const std::string& city, const char** used, const int length, const std::vector<std::string>& base);

std::string answer(std::vector<std::string>& used, const std::vector<std::string>& base);
const char* answer(const char** used, int* length, const std::vector<std::string>& base);

char last_letter(const char* city);
char last_letter(const std::string& city);
bool is_in_array(const char** arr, const int length, const char* str);

#endif
