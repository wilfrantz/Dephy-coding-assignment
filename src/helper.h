#ifndef HELPER_H
#define HELPER_H

#include "eprom.h"

namespace helper
{
    class Helper
    {
    public:
        Helper() = default;

        void processUserInput(int argumentCount, char **argumentVector);

        void processInvalidCommand()
        {
            std::cout << "Wrong Command." << std::endl;
            exit(1);
        }

    private:
    };

} // namespace helper

#endif // HELPER_H