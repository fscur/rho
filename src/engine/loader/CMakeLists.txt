cmake_minimum_required(VERSION 3.0.2)

if (MSVC)
    add_definitions(-Dloader_EXPORTS)
endif (MSVC)

include_directories(${INCLUDE_DIRS})
include_directories(${rho_INCLUDE_DIRS}/engine)
include_directories(${rho_INCLUDE_DIRS}/rho)

link_directories(${LIBS_DIRS})
find_package(FREEIMAGE REQUIRED)

file(GLOB header_files *.h)
file(GLOB source_files *.cpp)
file(GLOB natvis_files *.natvis)

add_library(loader SHARED ${source_files} ${header_files} ${natvis_files})

target_link_libraries(loader animation)
target_link_libraries(loader io)
target_link_libraries(loader rendering)
target_link_libraries(loader ${FREEIMAGE_LIBRARY})
target_link_libraries(loader ${ASSIMP_LIBRARY})

if (MINGW)
    set(install_folder ${CMAKE_CURRENT_SOURCE_DIR}/../../bin/${BIN_FOLDER})
    install(TARGETS loader RUNTIME DESTINATION ${install_folder})
endif(MINGW)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Yuprecompiled.h")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Fp$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.pch")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Fd$(IntDir)precompiled.pdb")
    
    add_custom_command(
        TARGET loader
        PRE_BUILD
        COMMAND ../../../../../scripts/pre_build_vc++/xcopy_n.bat \"$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.pdb\" \".\\$(IntDir)\")
        
    add_custom_command(
        TARGET loader
        PRE_BUILD
        COMMAND ../../../../../scripts/pre_build_vc++/xcopy_n.bat \"$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.idb\" \".\\$(IntDir)\")
        
    add_custom_command(
        TARGET loader
        PRE_BUILD
        COMMAND ../../../../../scripts/pre_build_vc++/xcopy_n.bat \"$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.sbr\" \".\\$(IntDir)\")
        
endif(MSVC)

set_target_properties(loader PROPERTIES FOLDER engine)