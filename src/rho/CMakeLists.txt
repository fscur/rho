cmake_minimum_required(VERSION 3.0.2)

include_directories("../../inc")
include_directories("../../src")

if(MSVC)
    file(GLOB header_files *.h)
    file(GLOB source_files *.cpp)
    add_library(rho STATIC ${source_files} ${header_files})
else()
    file(GLOB header_files *.h)
    list(REMOVE_ITEM header_files "precompiled.h")
    file(GLOB source_files *.cpp)
    add_library(rho STATIC ${source_files} ${header_files})
endif(MSVC)

find_package(FREETYPE REQUIRED)
message(${FREETYPE_INCLUDE_DIRS})
include_directories("../../inc/freetype")

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Ycprecompiled.h")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Fp$(IntDir)precompiled.pch")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Fd$(IntDir)precompiled.pdb")
endif(MSVC)