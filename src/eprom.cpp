#include "eprom.h"

namespace eprom
{

    /**
     * @brief: Process the user input and return the 
     * Corresponding command.
     * @param userInput
     * @return Eprom::VepromCommand
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
} // !eprom namespcae