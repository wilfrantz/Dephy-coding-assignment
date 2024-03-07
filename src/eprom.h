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

        // Zero arguments
        void eraseVeprom();
        std::vector<std::string> listFiles();

        // One argument
        void loadVeprom(const std::string &filePath);
        void writeToFile(const std::string &filePath);
        void createVeprom(const std::string &capacityKB);
        std::string readFile(const std::string &fileName);

        // Two arguments
        std::string readRaw(const std::string &address, int length);
        void writeRaw(const std::string &address, const std::string &data);

        ~Eprom() = default;

    private:
        std::string vEpromFile{"vEprom.bin"};
    };
} // !eprom namespace
#endif // EPROM_H