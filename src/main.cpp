#include "eprom.h"
#include "helper.h"

using namespace eprom;
using namespace helper;

int main(int argc, char **argv)
{
    Helper helper;
    helper.processUserInput(argc, argv);

    return 0;
}