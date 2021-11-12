#include <string>
#include <iostream>
#include <sstream>
#include "input.hpp"
#include "HashMap.hpp"


std::string getInput()
{
    std::string input; 
    std::getline(std::cin, input);
    return input;
}

void split(std::string x, std::string* array)
{
    std::stringstream s(x);
    std::string val;
    
    int index = 0;
    fill(array);
    while (s >> val)
    {
        // Checks if input is more than 3
        if (index > 2)
        {
            fill(array);
            break;
        }
        else
            array[index] = val;
        index += 1;
    }
}

void fill(std::string* array)
{
    for (int i = 0; i < 3; i++)
    {
        array[i] = "";
    }
}
