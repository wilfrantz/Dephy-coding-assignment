#include "eprom.h"

using namespace eprom;

int main(int argc, char **argv)
{
    Eprom vEprom;

    switch (argc)
    {
    case 2:
    {
        const std::string &userInput = argv[1];

        Eprom::VepromCommand command = vEprom.getVepromCommand(userInput);

        switch (command)
        {
        case 'CREATE':
            // Handle create command
            break;
        case 'LOAD':
            // Handle load command
            break;
        case 'WRITE_RAW':
            // Handle write_raw command
            break;
        case 'READ_RAW' :
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
        case 'ERASE':
            // Handle erase command
            break;
        case 'INVALID':
            std::cout << "Wrong Command." << std::endl;
            break;
        default:
            std::cout << "Wrong Command." << std::endl;
            exit(1);
        }
    }
    default:
        std::cout << "Wrong number of arguments" << std::endl;
        exit(1);
    }
}