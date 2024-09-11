#ifndef PROG_H
#define PROG_H
#include <vector>

int base_setup(std::vector<std::string>& base);
int cities_input(std::vector<std::string>* vec, std::vector<std::string>& base);
int process(int& overload_choice, std::vector<std::string>& in_cities, std::vector<std::string>& base);

char last_letter(const char* city);
char last_letter(std::string& city);
std::string get_answer(char ch, std::vector<std::string>& base);
const char* get_answer(char ch, int length, std::vector<std::string>& base);
bool city_name_check(std::string& city, std::vector<std::string>& base);

#endif
