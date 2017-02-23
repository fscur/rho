#include <precompiled.h>
#include "mesh.h"

namespace rho
{
    mesh::mesh(rho::geometry* geometry, rho::material* material) :
        component(componentType::MESH),
        _geometry(geometry),
        _material(material)
    {
    }

    mesh::~mesh()
    {
    }

    mesh::mesh(const mesh& mesh) :
        component(componentType::MESH),
        _geometry(mesh._geometry),
        _material(mesh._material)
    {
    }

    component* mesh::clone() const
    {
        auto m = static_cast<const mesh*>(this);
        return new mesh(*m);
    }
}