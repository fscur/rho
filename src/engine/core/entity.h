#pragma once
#include <rho.h>
#include "guid.h"

namespace rho
{
    class entity
    {
    protected:
        guid _guid;

    public:
        entity(guid guid) :
            _guid(guid)
        {
        }

        virtual ~entity()
        {
        }

        guid getGuid() const { return _guid; }
    };
}