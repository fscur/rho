cmake_minimum_required(VERSION 3.0.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Dapi_EXPORTS")

include_directories(${INCLUDE_DIRS})
include_directories(${rho_INCLUDE_DIRS}/engine)
include_directories(${rho_INCLUDE_DIRS}/rho)

link_directories(${LIBS_DIRS})

file(GLOB header_files *.h)
file(GLOB source_files *.cpp)
file(GLOB natvis_files *.natvis)

add_executable(00_getting_started ${source_files} ${header_files} ${natvis_files})

target_link_libraries(00_getting_started application)
target_link_libraries(00_getting_started animation)
target_link_libraries(00_getting_started loader)
target_link_libraries(00_getting_started data)

find_package(FREETYPE REQUIRED)
link_directories(${FREETYPE_LIBRARIES})
include_directories(${FREETYPE_INCLUDE_DIRS})
target_link_libraries(00_getting_started ${FREETYPE_LIBRARY})
target_link_libraries(00_getting_started ${LIBICONV_LIBRARY})
target_link_libraries(00_getting_started ${LIBINTL_LIBRARY})

if (MINGW)
    set(install_folder ${CMAKE_CURRENT_SOURCE_DIR}/../../bin/${BIN_FOLDER})
    install(TARGETS 00_getting_started RUNTIME DESTINATION ${install_folder})
endif(MINGW)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Yuprecompiled.h")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Fp$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.pch")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Fd$(IntDir)precompiled.pdb")
    
    add_custom_command(
        TARGET 00_getting_started
        PRE_BUILD
        COMMAND ../../../../../scripts/pre_build_vc++/xcopy_n.bat \"$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.pdb\" \".\\$(IntDir)\")
        
    add_custom_command(
        TARGET 00_getting_started
        PRE_BUILD
        COMMAND ../../../../../scripts/pre_build_vc++/xcopy_n.bat \"$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.idb\" \".\\$(IntDir)\")
        
    add_custom_command(
        TARGET 00_getting_started
        PRE_BUILD
        COMMAND ../../../../../scripts/pre_build_vc++/xcopy_n.bat \"$(SolutionDir)src\\rho\\rho.dir\\$(Configuration)\\precompiled.sbr\" \".\\$(IntDir)\")
        
endif(MSVC)

set_target_properties(00_getting_started PROPERTIES FOLDER apps)
