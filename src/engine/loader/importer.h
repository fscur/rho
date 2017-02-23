#pragma once
#include <rho.h>
#include "loaderApi.h"

#include <core/entityRepository.h>
#include <core/node.h>
#include <core/guid.h>
#include <core/model.h>
#include <core/mesh.h>
#include <rendering/camera.h>

#include "assimpImporter.h"

namespace rho
{
    class LOADER_API importer
    {
    //private:
    //    static node* readNode(
    //        const rapidjson::Value& node,
    //        const entityRepository<material>* materialsRepo,
    //        const entityRepository<geometry>* geometriesRepo);

    //    static guid convertToGuid(const char* bytesGuid);

    public:
        static image* importImage(const string& fileName, guid guid = guid::newGuid());

    //    static model* importModel(
    //        const string& fileName,
    //        entityRepository<material>* materialsRepo,
    //        entityRepository<geometry>* geometriesRepo);

    //    static image* loadImage(const string& fileName);
    //    static geometry* loadGeometry(const string& fileName);
    //    static material* loadMaterial(const string& fileName, const entityRepository<image>* texturesRepo);
    //    static model* loadModel(
    //        const string& fileName,
    //        const entityRepository<material>* materialsRepo,
    //        const entityRepository<geometry>* geometriesRepo);

    //    /*------------------- load .rho file ----------------------------*/

    //    static vector<node*> loadrhoFile(
    //        const string& fileName,
    //        const entityRepository<model>* modelsRepository);

    //    static rapidjson::Document* getJsonDocumentFromrhoFile(
    //        const string& rhoFileContents);

    //    static std::vector<node*> loadNodes(
    //        const rapidjson::Document* rhoJsonDoc,
    //        const entityRepository<model>* nodeRepository);

    //    static camera* loadCamera(const rapidjson::Document* rhoJsonDocument);
    //    /*------------------------------------------------------------------*/
    };
}