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
    // ---------------------------
    // This function creates a random string for a temp directory and checks for existence
    // ---------------------------

    std::string str { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
    std::random_device randDev;
    std::mt19937 generator(randDev());
    std::shuffle(str.begin(), str.end(), generator);

    auto dirpath = fs::path { "/tmp/tmp-" + str.substr(0, 32) };

    // ---------------------------
    // Existence of file check
    // ---------------------------
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

    std::string fileContent =
        "This is a text I'm writing at 1am\n"
        "I am a bit tired but it is what it is\n"
        "'One day, I'll be the greatest pokemon master' - Ash Ketchum\n"
        "What a great man he was...\n";

    // ---------------------------
    // Create a file
    // ---------------------------
    fs::path filePath = dirpath / "testfile.txt";
    std::ofstream ofile(filePath);
    ofile << fileContent << std::endl;
    ofile.close();
    std::cout << "Created file: " << (filePath) << std::endl;

    // ---------------------------
    // Reading a file
    // ---------------------------

    // Using '<<' operator
    // This skips whitespaces
    std::cout << "Reading file with <<: " << std::endl;
    std::ifstream ifile(filePath);
    std::string tempString;
    if (ifile.is_open()) {
        while (ifile.good()) {
            ifile >> tempString;
            std::cout << tempString;
        }
    } else {
        std::cout << "COULDN'T READ FILE";
    }
    ifile.close();
    std::cout << std::endl;

    // Using get()
    std::cout << "Reading file with get(): " << std::endl;
    ifile.open(filePath);
    char tempChar = 0;
    if (ifile.is_open()) {
        while (ifile) {
            tempChar = (char)ifile.get();
            std::cout << tempChar;
        }
    } else {
        std::cout << "COULDN'T READ FILE";
    }
    ifile.close();
    std::cout << std::endl;

    // Using getline()
    std::cout << "Reading file with getline(): " << std::endl;
    ifile.open(filePath);
    tempString = "";
    if (ifile.is_open()) {
        while (ifile) {
            std::getline(ifile, tempString);
            std::cout << tempString << std::endl;
        }
    }
    ifile.close();
    std::cout << std::endl;

    // ---------------------------
    // Deleting folder recursively
    // ---------------------------
    std::cout << "Deleting: " << dirpath << std::endl;
    fs::remove_all(dirpath);
}

// TODO:
//  * Expanding Tildes in Filenames
//  * Creating Temporary Files
//  * Locking a File
//  * Non-Blocking I/O
//  * Reading from many filehandles without blocking
//  * Processing every word in a file
//  * Trailing a growing file
//  * Reading a Configuration File (.json and .yml)
//  * Comparing the contents of two files
