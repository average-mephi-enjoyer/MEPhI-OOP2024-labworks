/*!
\file
\brief Header file of program functions

This file contains definitions of prototypes of functions used in the program.
*/
#ifndef PROG_H
#define PROG_H
#include <vector>

/*!
Creates a "database" of existing cities, loading them from an external text file.
\return Vector (std::vector<std::string>) with all known city names loaded.
\warning The text file is pre-created and is located in the same folder as the executable file. Deleting or moving the file will cause the program to stop working.
*/
std::vector<std::string> base_setup();

/*!
Reads the name of a city, if the std::string data type is used.
\param vec A reference to a vector (std::vector<std::string>) with previously used cities.
\param base A reference to a vector (std::vector<std::string>) with known cities.
\return A truth value indicating whether the city name was successfully read.
*/
bool city_in(std::vector<std::string>& vec, const std::vector<std::string>& base);

/*!
Reads the name of a city, if the data type is char* (C-style string).
\param used An array of previously used cities.
\param length A reference to an integer indicating the length of the array of used cities.
\param base A reference to a vector (std::vector<std::string>) with known cities.
\return A truth value indicating whether the city name was successfully read.
*/
bool city_in(const char** used, int &length, const std::vector<std::string>& base);

/*!
Checks the city name entered in std::string.
\param city Reference to the string containing the city name to check.
\param vec Reference to a vector (std::vector<std::string>) with previously used cities.
\param base Reference to a vector (std::vector<std::string>) with known cities.
\return A truth value indicating whether the entered city name satisfies all the rules of the game.
*/
bool city_name_check(const std::string& city, const std::vector<std::string>& vec, const std::vector<std::string>& base);

/*!
Checks the city name entered in char* (C-style string).
\param city Reference to the string containing the city name to check.
\param used Array with previously used cities.
\param length Integer indicating the length of the array of used cities.
\param base Reference to a vector (std::vector<std::string>) with known cities.
\return A truth value indicating whether the entered city name satisfies all the rules of the game.
*/
bool city_name_check(const std::string& city, const char** used, const int length, const std::vector<std::string>& base);

/*!
Performs a program move in the game (std::string overload).
\param used Reference to a vector (std::vector<std::string>) with previously used cities.
\param base Reference to a vector (std::vector<std::string>) with known cities.
\return String (std::string) with the name of the city that will be used by the program for its current move.
\throw std::runtime_error If there are no used cities or if the program has nothing to move: there are no more cities with the given letter.
*/
std::string answer(std::vector<std::string>& used, const std::vector<std::string>& base);

/*!
Performs a program move in the game (C-style string overload).
\param used An array of previously used cities.
\param length A reference to an integer indicating the length of the array of used cities.
\param base A reference to a vector (std::vector<std::string>) with known cities.
\return A C-style string with the name of the city that will be used by the program for its current move.
\throw std::runtime_error if there are no used cities or if the program has nothing to go to: there are no more cities with the given letter.
*/
const char* answer(const char** used, int &length, const std::vector<std::string>& base);

/*!
Defines the last letter of the city name for which there are cities (C-style string overload).
\param city Reference to a string (std::string) with the city name.
\return Symbol - the first letter for the city name to respond to.
*/
char last_letter(const std::string& city);

/*!
Defines the last letter of the city name for which there are cities (C-style string overload).
\param city C-style string with the city name.
\return Symbol - the first letter for the city name to respond to.
*/
char last_letter(const char* city);

/*!
Determines whether the string array contains the desired string.
\param arr Array of strings to search.
\param length Length of the array.
\param str C-style string to find in the array.
\return True if the search string is found, false otherwise.
*/
bool is_in_array(const char** arr, const int length, const char* str);

#endif // PROG_H
