#pragma once
#include <rho.h>
#include "coreApi.h"

namespace rho
{
    class command
    {
    public:
        command() { };
        virtual ~command() { };
        virtual bool getIsUndoable() { return true; }

        virtual void execute() { };
        virtual void executeUndo() { };
    };
}