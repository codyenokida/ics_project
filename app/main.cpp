#include <string>
#include <iostream>
#include "HashMap.hpp"
#include "input.hpp"
#include "checker.hpp"

int main()
{
    // Input of string
    std::string input;
    
    // Adds string to Array to check for keywords
    // EX: CREATE, LOGIN, REMOVE, etc.
    std::string* buffer = new std::string[3];

    // CREATE HashMap objet
    HashMap* hash = new HashMap();
    
    // Checks for "QUIT" keyword in array
    while (! quit(buffer))
    {
        input = getInput();
        split(input, buffer);
        isValid(buffer, hash);
    }

    // Delete for memory
    delete hash;
    delete[] buffer;


    return 0;
}

