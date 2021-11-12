#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <string>
#include "HashMap.hpp"


// Returns keyword
std::string getInput();

// Splits String into {Keyword, Username, Password}
void split(std::string x, std::string* array);

// Fills array with ""
void fill(std::string* array);

#endif
