#ifndef INPUTS_H
#define INPUTS_H
#include <cstring>
#include <string>
#include <limits>

#define PROMPT_OUT_OF_RANGE "Input ERROR! This value is out of range!\n"
#define PROMPT_EOF "Input closed. EOF at the end of input.\n"
#define PROMPT_BAD "Input fatal ERROR. cin.bad()\n"
#define PROMPT_FAIL "Input FAIL! Please, try again.\n>> "

template <typename T>
bool try_read(T& variable);
std::string string_read();
int int_read(int from = INT_MIN, int to = INT_MAX);

#endif
