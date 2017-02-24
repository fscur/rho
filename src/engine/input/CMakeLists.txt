cmake_minimum_required(VERSION 3.0.2)

if (MSVC)
    add_definitions(-Dinput_EXPORTS)
endif (MSVC)

include_directories(${INCLUDE_DIRS})
include_directories(${rho_INCLUDE_DIRS}/engine)
include_directories(${rho_INCLUDE_DIRS}/rho)

file(GLOB header_files *.h)
file(GLOB source_files *.cpp)
file(GLOB natvis_files *.natvis)

if(WIN32)
file(GLOB source_files_platform ./win64/*.cpp)
set(source_files ${source_files} ${source_files_platform})
endif(WIN32)

add_library(input SHARED 
     ${source_files}
     ${header_files}
     ${natvis_files})

target_link_libraries(input rho)
target_link_libraries(input core)

if (MINGW)
    set(install_folder ${CMAKE_CURRENT_SOURCE_DIR}/../../bin/${BIN_FOLDER})
    install(TARGETS input RUNTIME DESTINATION ${install_folder})
endif(MINGW)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Yuprecompiled.h")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Fp$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.pch")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Fd$(IntDir)precompiled.pdb")

    add_custom_command(
        TARGET input
        PRE_BUILD
        COMMAND ../../../../../scripts/pre_build_vc++/xcopy_n.bat \"$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.pdb\" \".\\$(IntDir)\")

    add_custom_command(
        TARGET input
        PRE_BUILD
        COMMAND ../../../../../scripts/pre_build_vc++/xcopy_n.bat \"$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.idb\" \".\\$(IntDir)\")
        
    add_custom_command(
        TARGET input
        PRE_BUILD
        COMMAND ../../../../../scripts/pre_build_vc++/xcopy_n.bat \"$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.sbr\" \".\\$(IntDir)\")

endif(MSVC)

set_target_properties(input PROPERTIES FOLDER engine)