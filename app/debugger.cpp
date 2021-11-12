#include <string>
#include <iostream>
#include "debugger.hpp"
#include "HashMap.hpp"


void debugOn(std::string* array, HashMap* hash)
{
    if (array[1] == "ON" && array[2] == "")
    {
        if (hash->getDebug() == true)
        {
            std::cout << "ON ALREADY" << std::endl;
        }
        else
        {
            std::cout << "ON NOW" << std::endl;
            hash->debugOn();
        }
    }
    else if (array[1] == "OFF" && array[2] == "")
    {
        if (hash->getDebug() == true)
        {
            std::cout << "OFF NOW" << std::endl;
            hash->debugOff();
        }
        else
        {
            std::cout << "OFF ALREADY" << std::endl;   
        }
    }
    else
    {
        hash->debugOff();
        std::cout << "INVALID" << std::endl;
    }
}


void bucketCount(std::string* array, HashMap* hash)
{
    if (array[1] == "COUNT" && array[2] == "" && hash->getDebug() == true)
    {
        std::cout << hash->bucketCount() << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}


void loadFactor(std::string* array, HashMap* hash)
{
    if (array[1] == "FACTOR" && array[2] == "" && hash->getDebug() == true)
    {
        std::cout << hash->loadFactor() << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

