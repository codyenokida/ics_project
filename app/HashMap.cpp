#include "HashMap.hpp"
#include <iostream>
    

unsigned int hashFunction(const std::string& x)
{
    int hashnum = 0;

    for (int i = 0; i < x.length(); i++)
    {
        hashnum += (int)x[i];
    }

    return hashnum;
}


// Constructor 
HashMap::HashMap()
{
    hasher = hashFunction;
    bucketNum = initialBucketCount;
    debug = false;
    valueCount = 0;

    HashTable = new Node*[initialBucketCount];
    for (int i = 0; i < initialBucketCount; i++)
    {
        HashTable[i] = nullptr;
    }
}

// Copy Constructor
HashMap::HashMap(const HashMap& x)
{
    hasher = x.hasher;
    bucketNum = x.bucketNum;
    debug = x.debug;
    valueCount = 0;
    Node** newHashTable = x.HashTable;
    HashTable = new Node*[bucketNum];
    valueCount = 0;
    for (int i = 0; i < bucketNum; i++)
    {
        HashTable[i] = nullptr;
    }
    for (int i = 0; i < bucketNum; i++)
    {
        if (newHashTable[i] != nullptr)
        {
            Node* oldNode;
            Node* newNode = newHashTable[i];
            while (newNode != nullptr)
            {
                this->add(newNode->key, newNode->value);
                oldNode = newNode;
                newNode = newNode->next;
                delete oldNode;
            }
        }
    }
}

// Object Assignment operator
HashMap& HashMap::operator=(const HashMap& hm)
{
    hasher = hm.hasher;
    bucketNum = hm.bucketNum;
    debug = hm.debug;
    Node** newHashTable = hm.HashTable;
    this->clear();
    delete[] HashTable;
    HashTable = new Node*[bucketNum];
    valueCount = 0;
    for (int i = 0; i < bucketNum; i++)
    {
        HashTable[i] = nullptr;
    }
    for (int i = 0; i < bucketNum; i++)
    {
        if (newHashTable[i] != nullptr)
        {
            Node* oldNode = nullptr;
            Node* newNode = newHashTable[i];
            while (newNode != nullptr)
            {
                this->add(newNode->key, newNode->value);
                oldNode = newNode;
                newNode = newNode->next;
                //delete oldNode;
            }
        }
    }
    return *this;
}


// Constructor (with haser function)
HashMap::HashMap(HashFunction hf)
{

    hasher = hf;
    bucketNum = initialBucketCount;
    debug = false;
    valueCount = 0;

    HashTable = new Node*[initialBucketCount];
    for (int i = 0; i < initialBucketCount; i++)
    {
        HashTable[i] = nullptr;
    }

}



// Deconstructor
HashMap::~HashMap()
{
    this->clear();
    delete[] HashTable;
}

void HashMap::add(const std::string& key, const std::string& value)
{
    int bucket = hasher(key) % bucketNum;
    if (HashTable[bucket] == nullptr)
    {
        HashTable[bucket] = new Node{key, value, nullptr};
        valueCount += 1;
    }
    else
    {
        // Gets the first Node object
        Node* first = HashTable[bucket];
        while (first->next != nullptr)
        {
            first = first->next;
        }
        if (first->key == key)
        {
        }
        else
        {
            first->next = new Node{key, value, nullptr};
            valueCount += 1;
        }
    }
    if (this->loadFactor() > 0.8)
    {
        this->reassign(key);
    }
}

void HashMap::reassign(const std::string& key)
{
    unsigned int oldBucketNum = bucketNum;
    bucketNum = bucketNum * 2 + 1;
    // Create new Hash Table with updated size
    Node** oldHashTable = HashTable;
    HashTable = new Node*[bucketNum];
    valueCount = 0;
    for (int i = 0; i < bucketNum; i++)
    {
        HashTable[i] = nullptr;
    }
    for (int i = 0; i < oldBucketNum; i++)
    {
        if (oldHashTable[i] != nullptr)
        {
            Node* oldNode;
            Node* newNode = oldHashTable[i];
            while (newNode != nullptr)
            {
                this->add(newNode->key, newNode->value);
                oldNode = newNode;
                newNode = newNode->next;
                delete oldNode;
            }
        }
    }
    delete[] oldHashTable;
}

void HashMap::remove(const std::string& key)
{
    int bucket = hasher(key) % bucketNum;
    if (HashTable[bucket] != nullptr)
    {
        Node* oldNode = nullptr;
        Node* newNode = HashTable[bucket];
        while (newNode->next != nullptr && newNode->key != key)
        {
            oldNode = newNode;
            newNode = newNode->next;
        }
        if (newNode->key == key)
        {
            // If first entry
            if (oldNode == nullptr)
            {
                Node* nextNode = newNode->next;
                delete newNode;
                HashTable[bucket] = nextNode;
                valueCount -= 1;
            }
            else
            {
                Node* nextNode = newNode->next;
                delete newNode;
                oldNode->next = nextNode;
                valueCount -= 1;
            }
        }
    }
}

bool HashMap::contains(const std::string& key) const
{
    int bucket = hasher(key) % bucketNum;
    if (HashTable[bucket] != nullptr)
    {
        Node* node = HashTable[bucket];
        while (node != nullptr)
        {
            if (node->key == key)
                return true;
            node = node->next;
        }
    }
    return false;
}

std::string HashMap::value(const std::string& key) const
{
    int bucket = hasher(key) % bucketNum;
    if (HashTable[bucket] != nullptr)
    {
        Node* newNode = HashTable[bucket];
        while (newNode != nullptr && newNode->key != key)
        {
            newNode = newNode->next;
        }
        return newNode->value;
    }
    return "";
}

unsigned int HashMap::size() const
{
    return valueCount;
}

unsigned int HashMap::bucketCount() const
{
    return bucketNum;
}

double HashMap::loadFactor() const
{
    return (double) valueCount / (double) bucketNum;
}

unsigned int HashMap::maxBucketSize() const
{
    unsigned int max = 0;
    for (int i = 0; i < bucketNum; i++)
    {
        unsigned int count = 0;
        Node* check = HashTable[i];
        while (check != nullptr)
        {
            count += 1;
            check = check->next;
        }
        if (count > max)
            max = count;
    }
    return max;
}

bool HashMap::getDebug() const
{
    return HashMap::debug;
}

void HashMap::debugOn()
{
    HashMap::debug = true;
}

void HashMap::debugOff()
{
    HashMap::debug = false;
}

void HashMap::clear()
{
    valueCount = 0;
    for (int i = 0; i < bucketNum; i++)
    {
        if (HashTable[i] != nullptr)
        {
            Node* oldNode = nullptr;
            Node* newNode = HashTable[i];
            while (newNode != nullptr)
            {
                oldNode = newNode;
                newNode = newNode->next;
                delete oldNode;
            }
        }
    }
    for (int i = 0; i < bucketNum; i++)
        HashTable[i] = nullptr;
}

