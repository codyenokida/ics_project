#include <string>
#include <iostream>
#include "HashMap.hpp"
#include "checker.hpp"
#include "debugger.hpp"

void isValid(std::string* array, HashMap* hash)
{
    // Check for QUIT
    if (array[0] == "QUIT" && array[1] == "" && array[2] == "")
    {
        std::cout << "GOODBYE" << std::endl;
    }
    // Check for CREATE
    else if (array[0] == "CREATE")
    {
        create(array, hash);
    }
    // Check for LOGIN
    else if (array[0] == "LOGIN")
    {
        login(array, hash);
    }
    // Check for REMOVE
    else if (array[0] == "REMOVE")
    {
        remove(array, hash);
    }
    // Check for CLEAR
    else if (array[0] == "CLEAR")
    {
        clear(array, hash);
    }
    // Check for DEBUG
    else if (array[0] == "DEBUG")
    {
        debugOn(array, hash);
    }
    // Check for BUCKET COUNT
    else if (array[0] == "BUCKET")
    {
        bucketCount(array, hash);
    }
    // Check for LOAD FACTOR
    else if (array[0] == "LOAD")
    {
        loadFactor(array, hash);
    }
    // ELSE all is considered INVALID
    else
        std::cout << "INVALID" << std::endl;
}

void create(std::string* array, HashMap* hash)
{
    
    if (array[1] == "" || array[2] == "")
        std::cout << "INVALID" << std::endl;
    else
    {
        if (hash->contains(array[1]))
        {
            std::cout << "EXISTS" << std::endl;
        }
        else
        {
            std::cout << "CREATED" << std::endl;
            hash->add(array[1], array[2]);
        }
    }

}

void login(std::string* array, HashMap* hash)
{
    // Check for LOGIN COUNT
    if (array[1] == "COUNT" && array[2] == "" && hash->getDebug() == true)
    {
        std::cout << hash->size() << std::endl;
    }
    // Check for regular LOGIN
    else if (array[1] == "" || array[2] == "")
        std::cout << "INVALID" << std::endl;
    else
    {
        if (hash->contains(array[1]) && hash->value(array[1]) == array[2])
            std::cout << "SUCCEEDED" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }

}


bool quit(std::string* array)
{
    if (array[0] == "QUIT" && array[1] == "" && array[2] == "")
    {
        return true;
    }
    return false;
}

void remove(std::string* array, HashMap* hash)
{
    if (array[1] != "" && array[2] == "")
    {

        if (hash->contains(array[1]))
        {
            hash->remove(array[1]);
            std::cout << "REMOVED" << std::endl;
        }
        else
        {
            std::cout << "NONEXISTENT" << std::endl;
        }
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }

}

void clear(std::string* array, HashMap* hash)
{
    if (array[1] == "" && array[2] == "")
    {
        hash->clear();
        std::cout << "CLEARED" << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}



