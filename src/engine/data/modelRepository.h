#pragma once
#include <rho.h>

#include <core/guid.h>

#include "dataApi.h"
#include "abstractions/iModelRepository.h"
#include "model/modelDTO.h"
#include "model/index.h"

namespace rho
{
    class modelRepository : public iModelRepository
    {
    public:
        DATA_API modelRepository(string libraryPath);
        DATA_API ~modelRepository();

        DATA_API virtual modelDTO getModelByIndex(const int index) override;
        DATA_API virtual modelDTO getModelById(const rho::guid& id) override;

    private:
        const string MODELS_INDEX_FILE_NAME = "models.index";

        string _libraryPath;
        index _index;
    };
}