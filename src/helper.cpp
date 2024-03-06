#include "helper.h"
#include "eprom.h"

using namespace eprom;

namespace helper
{
    void Helper::processUserInput(int argumentCount, char **argumentVector)
    {
        Eprom vEprom;
        std::string userInput{};
        // std::string vEpromFile{};

        switch (argumentCount)
        {
        case 2: // Handle erase command
        {
            userInput = argumentVector[1];
            Eprom::VepromCommand command = vEprom.getVepromCommand(userInput);

            switch (command)
            {
            case 'ERASE':
                vEprom.eraseVeprom();

                break;
            case 'INVALID':
                processInvalidCommand();
                break;
            }
            break;
        }
        case 3: // Handle orther commands.
        {
            userInput = argumentVector[1];
            const std::string &option = argumentVector[2];
            Eprom::VepromCommand command = vEprom.getVepromCommand(userInput);

            switch (command)
            {
            case 'CREATE': //  create virtual EPROM chip with a specified capacity
                vEprom.createVeprom(option);
                break;
            case 'LOAD': // Handle load command

                break;
            case 'WRITE_RAW':
                // Handle write_raw command
                break;
            case 'READRAW':
                // Handle read_raw command
                break;
            case 'WRITE':
                // Handle write command
                break;
            case 'LIST':
                // Handle list command
                break;
            case 'READ':
                // Handle read command
                break;
            case 'INVALID':
                processInvalidCommand();
                break;
            }
        default:
            std::cout << "Wrong number of arguments" << std::endl;
            exit(1);
        }
        }
    }
} // !namespace helper