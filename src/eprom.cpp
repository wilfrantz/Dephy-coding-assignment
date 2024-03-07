#include "eprom.h"

namespace eprom
{
    /**
     * @brief: Process the user input and return the
     * Corresponding command.
     * @param userInput
     * @return command
     */
    Eprom::VepromCommand Eprom::getVepromCommand(const std::string &userInput)
    {
        if (userInput == "create")
        {
            return CREATE;
        }
        else if (userInput == "load")
        {
            return LOAD;
        }
        else if (userInput == "write_raw")
        {
            return WRITE_RAW;
        }
        else if (userInput == "read_raw")
        {
            return READ_RAW;
        }
        else if (userInput == "write")
        {
            return WRITE;
        }
        else if (userInput == "list")
        {
            return LIST;
        }
        else if (userInput == "read")
        {
            return READ;
        }
        else if (userInput == "erase")
        {
            return ERASE;
        }
        else
        {
            return INVALID;
        }
    }

    /**
     * @brief
     * Usage: veprom create 256 creates a new virtual EPROM chip with a capacity of 256 KB.
     *It outputs the path of the file used to store the vEPROM. This is the vEprom that’ll
     *be used when the other commands are called.
     */
    void Eprom::createVeprom(std::string capacityKB)
    {
        // Calculate the size in bytes
        int sizeKB = stoi(capacityKB);
        std::streamsize fileSize = sizeKB * 1024;

        // Create a vector to hold the data (all zeros for an empty file)
        std::vector<char> data(fileSize, 0);

        // Open the file for writing
        std::ofstream file(vEpromFile, std::ios::out | std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "Failed to open file for writing." << std::endl;
            return;
        }

        // Write data to the file
        file.write(data.data(), fileSize);

        file.close();

        std::cout << "Virtual EPROM file successfully created at: " << vEpromFile << std::endl;
    }

    /** @brief: loads a vEPROM file that’ll be used when the other commands are called.
     * @param: /path/to/veprom/file.
     */
    void Eprom::loadVeprom(const std::string &filePath)
    {
        this->vEpromFile = filePath;
    }

    /**
     * @brief: Method to erase the EPROM back to its original state
     */
    void Eprom::eraseVeprom()
    {
        // Open the file for truncation
        std::ofstream file(vEpromFile, std::ios::out | std::ios::binary | std::ios::trunc);
        if (!file.is_open())
        {
            std::cerr << "Failed to open file for erasing." << std::endl;
            return;
        }

        file.close();

        std::cout << "Virtual EPROM file successfully erased." << std::endl;
    }

} // !eprom namespcae