#include <precompiled.h>
#include "keyNotFoundException.h"

namespace rho
{
    keyNotFoundException::keyNotFoundException(string message) :
        exception::exception(message)
    {
    }
}
