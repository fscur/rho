#pragma once
#include "coreApi.h"
#include <rho.h>

#include <diagnostic\stackSymbol.h>

namespace rho
{
    class exception :
        public std::runtime_error
    {
    private:
        vector<stackSymbol> _stackTrace;
    public:
        CORE_API exception(string message);
        vector<stackSymbol> getStackTrace() const { return _stackTrace; }
    };
}