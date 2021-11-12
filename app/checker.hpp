#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <iostream>
#include <string>
#include "HashMap.hpp"


// Checks if Keyword is valid; if so, checks if username and password are OK
void isValid(std::string* array, HashMap* hash);

// LOGIN Function 
void login(std::string* array, HashMap* hash);

// CREATE Function
void create(std::string* array, HashMap* hash);

// REMOVE Function
void remove(std::string* array, HashMap* hash);

// CLEAR Function
void clear(std::string* array, HashMap* hash);

// QUIT Function
bool quit(std::string* array);


#endif
