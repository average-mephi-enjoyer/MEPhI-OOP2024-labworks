/*!
\file
\brief Input function header file

This file contains definitions of prototypes of input functions for various data,
as well as dialog messages used by these functions.
*/

#ifndef INPUTS_H
#define INPUTS_H
#include <cstring>
#include <string>
#include <limits>

#define PROMPT_OUT_OF_RANGE "Input ERROR! This value is out of range!\n" ///<  Integer input error message: notifies you that the given value is out of range.
#define PROMPT_EOF "Input closed. EOF at the end of input.\n" ///< Message about input stream error (std::cin.eof()) and about the end of keyboard input.
#define PROMPT_BAD "Input fatal ERROR. cin.bad()\n" ///< Reporting a critical input stream error (std::cin.bad()).
#define PROMPT_FAIL "Input FAIL! Please, try again.\n>> " ///< Input stream error message (std::cin.fail()).

template <typename T> ///< Template for input functions.

/*!
Reads the value for a variable from the keyboard.
\param variable A reference to the variable into which the value should be put.
\return A truth value indicating whether the variable was successfully read.
\throw std::runtime_error If an input stream error occurs (std::cin.bad() or std::cin.eof()).
*/
bool try_read(T& variable);

/*!
Inputs a string of type std::string using the try_read() function
\return The string that was successfully input.
*/
std::string string_read();

/*!
Enters an int value in the given range.
\param from,to The range bounds. By default, they are set to the maximum allowed for this data type.
\return The int value that was successfully read.
*/
int int_read(int from = INT_MIN, int to = INT_MAX);

#endif // INPUTS_H
