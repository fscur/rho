#pragma once
#include <rho.h>

#include <core/model.h>

#include <data/abstractions/iModelDataService.h>

namespace getting_started
{
    class library
    {
    private:
        rho::iModelDataService* _modelDataService;

    public:
        library(rho::iModelDataService* modelDataService);
        ~library();

        rho::model* getModelByIndex(const int index);
        rho::model* library::getModelById(const rho::guid& guid);
    };
}