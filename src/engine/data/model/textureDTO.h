#pragma once
#include <rho.h>

#include <core/guid.h>

namespace rho
{
    struct textureDTO
    {
        guid guid;
        string imageFileName;

        template <typename Archive>
        void serialize(Archive& archive)
        {
            archive(
                cereal::make_nvp("Guid", guid),
                cereal::make_nvp("ImageFileName", imageFileName)
            );
        }
    };
}