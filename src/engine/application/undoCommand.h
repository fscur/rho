#pragma once
#include "commandsManager.h"

namespace rho
{
    class undoCommand :
        public command
    {
    private:
        commandsManager* _commandsManager;

    public:
        undoCommand(commandsManager* commandsManager)
            : command()
        {
            _commandsManager = commandsManager;
        }

        void execute() override
        {
            _commandsManager->undo();
        }

        bool getIsUndoable() override { return false; }
    };
}