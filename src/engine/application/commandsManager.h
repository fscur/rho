#pragma once
#include <rho.h>
#include "applicationApi.h"

#include <core\command.h>
#include <input\mouseEventArgs.h>
#include <input\keyboardEventArgs.h>
#include "shortcut.h"

namespace rho
{
    class commandsManager
    {
    private:
        vector<shortcut> _shortcuts;
        std::stack<command*> _undo;
        std::stack<command*> _redo;
        vector<keycode> _pressedKeys;
        vector<shortcut> _commandShortcuts;

    private:
        void onKeyDown(rho::keyboardEventArgs* e);
        void onKeyUp(rho::keyboardEventArgs* e);
        void clearRedo();
    public:
        APPLICATION_API commandsManager();
        APPLICATION_API ~commandsManager();

        APPLICATION_API void addShortcut(shortcut shortcut);
        APPLICATION_API void undo();
        APPLICATION_API void redo();
        APPLICATION_API void executeCommand(command* command);
        APPLICATION_API void pushCommand(command* command);
    };
}