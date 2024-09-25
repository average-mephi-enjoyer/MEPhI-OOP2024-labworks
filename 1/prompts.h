/*!
\file
\brief Dialog messages header file

This file contains the definitions of all dialog messages.
It is used to clean up the code and make it easier to read.
*/
#ifndef PROMPTS_H
#define PROMPTS_H

#define PROMPT_INTRO "=== THIS PROGRAM SIMULATES THE GAME OF CITIES ===\nPlease enter the names of Russian cities starting with the last letter of the last city (the first city can be any)." ///< Greeting message. Explains to the user what exactly to do (enter city names starting with a random letter, and then starting with the last letter of the last used city).
#define PROMPT_OVERLOAD_CHOICE "What overloading do you want to use?\n1 - C-Style string;\n2 - std::string;\n>> " ///< A message prompting the user to select a function overload option that will be used during the game. Options: use a C-style string or use a string from C++ (std::string).
#define PROMPT_GAME_BEGIN "Let the game begin! It's your turn." ///< A message preceding the start of the game and notifying the user that he will start the game.
#define PROMPT_CITY_INPUT "Please enter the name of the city or press Ctrl+Z\n>> " ///< A message prompting the user to enter the name of a city in their turn or to end the game by pressing the appropriate key combination.
#define PROMPT_INPUT_END "City names input completed." ///< An error message that appears at the end of the game at the user's request when keyboard input is finished (std::cin.eof() error is caused).
#define PROMPT_ERR_INPUT "Input ERROR!\nPlease follow the rules of the game:\n1. enter the names of russian cities only\n2. do not re-enter already used cities;\n3. do not use forbidden characters;\n4. always enter cities ending with the last letter of the last city.\n" ///< A message that appears when there is an error in data input (a city that does not exist in the database was entered, prohibited characters were used, the name of the city was entered again, the game principles were violated).
#define PROMPT_EMPTY_LIST "Program ERROR! Cities list is empty.\n" ///< An error message that occurs if the user misses their turn during the first move (the list of cities is empty at the time of the program's turn).
#define PROMPT_NO_ANSWER "No cities in my base :((" ///< An error message that occurs when the program has no move options (the list of unused city names known to the program is empty, there are no unused city names starting with this letter).
#define PROMPT_ANSWER "<< My city: " ///< The message preceding the program's response. After it follows the name of the city.

#endif // PROMPTS_H
