#include <precompiled.h>
#include "importResourceException.h"

namespace rho
{
    importResourceException::importResourceException(string message) :
        importResourceException::importResourceException(message, "Resource path not provided")
    {
    }

    importResourceException::importResourceException(string message, string resourcePath) :
        exception::exception(message),
        _resourcePath(resourcePath)
    {
    }
}