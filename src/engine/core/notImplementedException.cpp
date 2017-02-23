#include <precompiled.h>
#include "notImplementedException.h"

namespace rho
{
    notImplementedException::notImplementedException() :
        exception::exception("A not implemented method was called")
    {
    }
}
