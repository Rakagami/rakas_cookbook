#include <format>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/**
 * This file includes string operation related recipes
 */

int main()
{
    std::string str1 = "string1";
    std::string str2 = "string2";

    std::cout << std::format("String1: '{}', String2: '{}'\n", str1, str2);

    // ---------------------
    // Concatenating strings
    // ---------------------
    std::cout << std::format("Concat: '{}'\n", str1 + str2);

    // ---------------------
    // Detecting a substring
    // ---------------------
    std::string str3 = "this is a full sentence saved as a string";

    std::cout << std::format("Sentence: '{}'", str3) << std::endl;
    if (str3.find("sentence") != std::string::npos) {
        std::cout << "'sentence' is a substring" << std::endl;
    }

    if (!(str3.find("pokemon") != std::string::npos)) {
        std::cout << "'pokemon' is not substring" << std::endl;
    }

    // ---------------------
    // Counting substrings
    // ---------------------
    std::string str4 =
        "This is a multiline string.\n"
        "The string literals are concatenated by the compiler\n"
        "Like this, it makes it easy to write multiline strings and make it readable in the source "
        "code.\n"
        "Hello World! Strings are cool and all, but when does this end?\n"
        "Strings oh strings, hear my praying, I this is the final line break\n";

    std::cout << "This is the multiline string:" << std::endl;

    std::cout << str4 << std::endl;

    std::vector<size_t> posVector;
    size_t pos = 0;
    size_t count = 0;
    std::string tempStr = str4;
    while ((pos = tempStr.find("string")) != std::string::npos) {
        posVector.push_back(pos);
        tempStr = tempStr.substr(pos + 1);
        count++;
    }

    std::cout << "'string' count: " << count << std::endl;

    // NOLINTNEXTLINE
    std::stringstream ss;
    for (auto it = posVector.begin(); it != posVector.end(); it++) {
        if (it != posVector.begin()) {
            ss << " ";
        }
        ss << *it;
    }

    std::cout << "Positions: " << ss.str() << std::endl;
}
