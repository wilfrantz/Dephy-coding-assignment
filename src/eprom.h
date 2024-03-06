#ifndef EPROM_H
#define EPROM_H

#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <curl/curl.h>
#include <cstdlib>
#include <thread>

namespace eprom
{

    class Eprom
    {

    public:
        Eprom() = default;

        enum VepromCommand
        {
            CREATE,
            LOAD,
            WRITE_RAW,
            READ_RAW,
            WRITE,
            LIST,
            READ,
            ERASE,
            INVALID
        };

        VepromCommand getVepromCommand(const std::string &userInput);

        // TODO: Implement the commands

        // Function to create a new virtual EPROM chip with a specified capacity
        std::string createVeprom(int capacityKB);
        // Method to load a vEPROM file
        std::string loadVeprom(const std::string &filePath);
        // Method to write a raw string of bytes to a specific address on the virtual EPROM chip
        void writeRaw(const std::string &address, const std::string &data);
        // Method to read the values stored at a specific address and length on the virtual EPROM chip
        std::string readRaw(const std::string &address, int length);
        // Method to write a file to the virtual EPROM chip
        void writeToFile(const std::string &filePath);
        // Method to list the files on the virtual EPROM chip
        std::vector<std::string> listFiles();
        // Method to read a file from the virtual EPROM chip
        std::string readFile(const std::string &fileName);
        // Method to erase the EPROM back to its original state
        void eraseVeprom();

        ~Eprom() = default;

    private:
    };
} // !eprom namespace
#endif // EPROM_H