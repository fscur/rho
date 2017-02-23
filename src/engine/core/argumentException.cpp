#include <precompiled.h>
#include "argumentException.h"

namespace rho
{
    argumentException::argumentException(string message) :
        exception::exception(message)
    {
    }
}
