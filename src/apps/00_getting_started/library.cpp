#include <precompiled.h>
#include "library.h"

#include <io\path.h>

using namespace rho;

namespace getting_started
{
    library::library(iModelDataService* modelDataService) :
        _modelDataService(modelDataService)
    {
    }

    library::~library()
    {
    }

    model* library::getModelByIndex(const int index)
    {
        return _modelDataService->getModelByIndex(index);
    }

    model* library::getModelById(const rho::guid& id)
    {
        return _modelDataService->getModelById(id);
    }
}