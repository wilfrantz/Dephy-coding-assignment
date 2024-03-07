#include "helper.h"
#include "eprom.h"

using namespace eprom;

namespace helper
{
    void Helper::processUserInput(int argumentCount, char **argumentVector)
    {
        Eprom vEprom;
        std::string userInput{};
        Eprom::VepromCommand command = vEprom.getVepromCommand(userInput);

        switch (argumentCount)
        {
        case 2: // Handle 2 CLA.
        {
            switch (command)
            {
            case 'ERASE':
                vEprom.eraseVeprom();
                break;
            case 'LIST':
                vEprom.listFiles();
                break;
            case 'INVALID':
                processInvalidCommand();
                break;
            }
        }
        case 3: // Handles 3 CLA.
        {
            userInput = argumentVector[1];
            const std::string &option = argumentVector[2];

            switch (command)
            {
            case 'CREATE': //  create virtual EPROM chip with a specified capacity
                vEprom.createVeprom(option);
                break;
            case 'LOAD': // loads a vEPROM file.
                vEprom.loadVeprom(option);
                break;
            case 'WRITE': // Handle write command
                vEprom.writeToFile(option);
                break;
            case 'READ': // Handle read command
                vEprom.readFile(option);
                break;
            case 'INVALID':
                processInvalidCommand();
                break;
            }
        }
        case 4: // Handle 4 CLA.
        {
            userInput = argumentVector[1];
            const std::string &data = argumentVector[3];
            const std::string &address = argumentVector[2];

            switch (command)
            {
            case 'WRITE_RAW': // Handle write_raw command
                vEprom.writeRaw(address, data);
                break;
            case 'READRAW': // Handle read_raw command
                vEprom.readRaw(address, stoi(data));
                break;
            case 'INVALID':
                processInvalidCommand();
                break;
            }
        }
        default:
            std::cout << "Wrong number of arguments" << std::endl;
            exit(1);
        }
    }
} // !namespace helper