#pragma once
#include <core\command.h>

namespace rho
{
    struct shortcut
    {
        shortcut(std::vector<keycode> keys, std::function<command*(void)> commandFunc) :
            keys(keys),
            commandFunc(commandFunc)
        {
        }

        std::vector<keycode> keys;
        std::function<command*(void)> commandFunc;
    };
}