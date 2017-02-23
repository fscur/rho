#pragma once
#include <rho.h>

#include <core/base64.h>
#include <core/guid.h>

namespace cereal
{
    template <typename Archive>
    rho::string save_minimal(Archive& archive, const rho::guid& value)
    {
        _unused(archive);
        return value.toStringBase64();
    };

    template <typename Archive>
    void load_minimal(Archive& archive, rho::guid& value, const rho::string& guidString)
    {
        _unused(archive);
        value = rho::guid(rho::base64::decode(guidString));
    };
}