//
// Created by niklas on 19.09.18.
//

#ifndef SOUNDEX_H
#define SOUNDEX_H
//#include <iostream>
#include <string>

static const size_t MaxCodeLength{4};

class Soundex {

public:
    std::string encode(const std::string& word) const {
        return zeroPad(head(word) + encodedDigits(word));
    }

private:
    std::string head(const std::string& word) const {
        return word.substr(0, 1);
    }

    std::string encodedDigits(const std::string& word) const {
        if (word.length() > 1) return encodedDigit();
        return "";
    }

    std::string encodedDigit() const {
        return "1";
    }

    std::string zeroPad(const std::string& word) const {
        auto zerosNeeded = MaxCodeLength - word.length();
        return word + std::string(zerosNeeded, '0');
    };
};

#endif //SOUNDEX_H
