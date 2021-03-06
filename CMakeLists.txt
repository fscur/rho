cmake_minimum_required(VERSION 3.0.2)

project(rho)
set_property(GLOBAL PROPERTY DEBUG_CONFIGURATIONS "Debug;DebugWithMemoryTracking")

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS TRUE)
SET_PROPERTY(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER !CMake)

add_subdirectory(src/rho)
add_subdirectory(src/engine/diagnostic)
add_subdirectory(src/engine/core)
add_subdirectory(src/engine/input)
add_subdirectory(src/engine/animation)
add_subdirectory(src/engine/io)
add_subdirectory(src/engine/loader)
add_subdirectory(src/engine/data)
add_subdirectory(src/engine/rendering)
add_subdirectory(src/engine/application)

add_subdirectory(src/apps/00_getting_started)
add_subdirectory(src/apps/01_command_buffer)

set (dlls_dir ${CMAKE_CURRENT_SOURCE_DIR}/libs/${SOLUTION_PLATFORM})
set (library_dir ${CMAKE_CURRENT_SOURCE_DIR}/library)
set (resources_dir ${CMAKE_CURRENT_SOURCE_DIR}/resources)
set (locale_dir ${CMAKE_CURRENT_SOURCE_DIR}/locale)
set (src_dir ${CMAKE_BINARY_DIR}/src)

if (WIN32)
    file(GLOB dll_files ${dlls_dir}/*.dll)
    file(GLOB tlb_files ${dlls_dir}/*.tlb)
elseif(APPLE)
    file(GLOB dll_files ${dlls_dir}/*.*)
endif(WIN32)

file(GLOB image_files ${image_dir}/*.*)

set_target_properties(diagnostic PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})
set_target_properties(core PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})
set_target_properties(input PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})
set_target_properties(animation PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})
set_target_properties(io PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})
set_target_properties(loader PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})
set_target_properties(data PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})
set_target_properties(rendering PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})
set_target_properties(application PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})

set_target_properties(00_getting_started PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})
set_target_properties(01_command_buffer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})


if (MSVC)
    foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
        string(TOLOWER ${OUTPUTCONFIG} OUTPUTCONFIG)
        set (bin_dir ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER}/${OUTPUTCONFIG})
        
        install(FILES ${dll_files} DESTINATION ${bin_dir} CONFIGURATIONS ${OUTPUTCONFIG})
        install(DIRECTORY ${resources_dir} DESTINATION ${bin_dir} CONFIGURATIONS ${OUTPUTCONFIG})
        install(DIRECTORY ${library_dir} DESTINATION ${bin_dir} CONFIGURATIONS ${OUTPUTCONFIG})
        install(DIRECTORY ${locale_dir} DESTINATION ${bin_dir} CONFIGURATIONS ${OUTPUTCONFIG})
    endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)
    
else()
        set (bin_dir ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BIN_FOLDER})
        install(FILES ${dll_files} DESTINATION ${bin_dir})
        install(DIRECTORY ${resources_dir} DESTINATION ${bin_dir})
        install(DIRECTORY ${library_dir} DESTINATION ${bin_dir})
        install(DIRECTORY ${locale_dir} DESTINATION ${bin_dir})
endif(MSVC)