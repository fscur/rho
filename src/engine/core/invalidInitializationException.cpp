#include <precompiled.h>
#include "invalidInitializationException.h"

namespace rho
{
    invalidInitializationException::invalidInitializationException(string message) :
        exception::exception(message)
    {
    }
}
