//
// Created by niklas on 05.10.18.
//

#include <gmock/gmock.h>
#include <string>
#include <unordered_map>
#include <iostream>


class Soundex
        {
public:
    std::string encode(std::string word) const
    {
        // Create an empty unordered_map
        std::unordered_map<std::string, std::string> wordMap = {
                {{ "b", "1" }, { "f", "1" }, { "p", "1" }, { "v", "1" }}
        };

        std::unordered_map<std::string, std::string>::const_iterator wordMapIterator = wordMap.find(word.substr(1,2));
        word.replace(1, 2, (*wordMapIterator).second);

        return zeroPad(word);
    }

private:
    std::string zeroPad(std::string &word) const
    {
        if (word.length() < 4)
            word.append(4 - word.length(), '0');
        return word;
    }
};

class SoundexFixture : public testing::Test
{
public:
    Soundex unit{};
};

TEST_F(SoundexFixture, WhenSingleLetterReturnLetter)
{
    ASSERT_EQ("A", unit.encode("A").substr(0,1));
    ASSERT_EQ("X", unit.encode("X").substr(0,1));
}

TEST_F(SoundexFixture, WhenLessThan4Digits_ThenZeroPad)
{
    ASSERT_EQ("C000", unit.encode("C"));
}

TEST_F(SoundexFixture, Whenbfpv_ThenReplaceWith1)
{
    ASSERT_EQ("D100", unit.encode("Db"));
    ASSERT_EQ("D100", unit.encode("Df"));
    ASSERT_EQ("D100", unit.encode("Dp"));
    ASSERT_EQ("D100", unit.encode("Dv"));
}