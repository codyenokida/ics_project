// HashMapTests.cpp
//
// ICS 45C Spring 2019
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided a few tests
// already, though I've commented them out, because they won't compile
// until you've implemented some things.

#include <gtest/gtest.h>
#include "HashMap.hpp"


TEST(HashMapTests, sizeOfNewlyCreatedHashMapIsZero)
{
    HashMap empty;
    ASSERT_EQ(0, empty.size());
}


TEST(HashMapTests, emptyMapContainsNoKeys)
{
    HashMap empty;
    ASSERT_FALSE(empty.contains("first"));
    ASSERT_FALSE(empty.contains("second"));
}


TEST(HashMapTests, containKeyAfterAddingIt)
{
    HashMap hm;
    hm.add("Boo", "perfect");
    ASSERT_TRUE(hm.contains("Boo"));
}

// OK HERE ARE TESTS I MADE
TEST(HashMapTests, bucketCountIncreasesAfterLoadFactor)
{
    HashMap hm;
    std::string key = "";
    std::string value = "";
    // Adding values => LF greater than 0.8
    for (int i = 0; i < 9; i++)
    {
        hm.add(key, value);
        key += "1";
        value += "1";
    }
    ASSERT_EQ(21, hm.bucketCount());
}

TEST(HashMapTests, maxBucketCount)
{
    HashMap hm;
    // "a", "k", and "u" have same hashed value => maxBucketCount == 3
    hm.add("a", "password");
    hm.add("k", "password");
    hm.add("u", "password");

    // Not same hashed value
    hm.add("l", "password");
    ASSERT_EQ(3, hm.maxBucketSize());
}

TEST(HashMapTests, checkSize)
{
    HashMap hm;
    hm.add("user1", "password");
    hm.add("user2", "password");
    hm.add("user3", "password");
    ASSERT_EQ(3, hm.size());
}

TEST(HashMapTests, checkRemove)
{
    HashMap hm;
    hm.add("user1", "password");
    hm.add("user2", "password");
    hm.remove("user1");
    ASSERT_EQ(1, hm.size());
}

TEST(HashMapTests, checkLoadFactor)
{
    HashMap hm;
    std::string key = "";
    std::string value = "";
    // Adding 8 values LF == 0.8
    for (int i = 0; i < 8; i++)
    {
        hm.add(key, value);
        key += "1";
        value += "1";
    }
    ASSERT_EQ(10, hm.bucketCount());
    // Making LF greater than 0.8
    hm.add("1more", "password");
    ASSERT_EQ(21, hm.bucketCount());
}

TEST(HashMapTests, assigningOperatorCheck)
{
    HashMap hm;
    HashMap hm1;
    hm.add("user", "password");
    hm1 = hm;
    ASSERT_EQ(hm.size(), hm1.size());
}

TEST(HashMapTests, checkClear)
{
    HashMap hm;
    hm.add("user", "password");
    hm.clear();
    ASSERT_EQ(0, hm.maxBucketSize());
}
