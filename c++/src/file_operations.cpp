#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
namespace fs = std::filesystem;

fs::path randomDirName()
{
    // This function creates a random string for a temp directory and checks for existence
    
    std::string str { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
    std::random_device randDev;
    std::mt19937 generator(randDev());
    std::shuffle(str.begin(), str.end(), generator);

    auto dirpath = fs::path { "/tmp/tmp-" + str.substr(0, 32) };

    // Existence of file check
    while (fs::exists(dirpath)) {
        dirpath = fs::path { "/tmp/tmp-" + str.substr(0, 32) };
    }

    return dirpath;
}

int main()
{
    auto dirpath = randomDirName();
    std::cout << "Creating directory " << dirpath << std::endl;
    fs::create_directory(dirpath);
}


// TODO:
//  * Reading and Writing to Files
//  * Expanding Tildes in Filenames
//  * Creating Temporary Files
//  * Using the /tmp/ folder for temporary
//  * Locking a File
//  * Non-Blocking I/O
//  * Reading from many filehandles without blocking
//  * Processing every word in a file
//  * Trailing a growing file
//  * Reading a Configuration File (.json and .yml)
//  * Comparing the contents of two files
