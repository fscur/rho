set(CMAKE_CXX_FLAGS "-DMINGW -D_DEBUG -std=c++11 -Wall -Werror -pedantic -Dapi_EXPORTS" CACHE STRING "c++ compiler flags" FORCE)
set(ROOT_DIR "../../")
set(BIN_FOLDER "win64/gcc/debug" CACHE STRING "")
set(SOLUTION_PLATFORM "win64/gcc" CACHE STRING "")
set(rho_INCLUDE_DIRS "${ROOT_DIR}src/" CACHE PATH "")
set(rho_TESTS_INCLUDE_DIRS "${ROOT_DIR}tests/" CACHE PATH "")
set(INCLUDE_DIRS "${ROOT_DIR}inc/" CACHE PATH "")
set(LIBS_DIRS "${CMAKE_SOURCE_DIR}/../../../libs/win64/gcc" CACHE PATH "")
set(FREETYPE_INCLUDE_DIR_freetype2 "${ROOT_DIR}inc/freetype" CACHE PATH "")
set(FREETYPE_INCLUDE_DIR_ft2build "${ROOT_DIR}inc/freetype" CACHE PATH "")
set(FREETYPE_LIBRARY "${CMAKE_SOURCE_DIR}/../../../libs/win64/gcc/libfreetype.a" CACHE PATH "")
set(LIBICONV_LIBRARY "${CMAKE_SOURCE_DIR}/../../../libs/win64/gcc/libiconv.a" CACHE PATH "")
set(LIBINTL_LIBRARY "${CMAKE_SOURCE_DIR}/../../../libs/win64/gcc/libintl.a" CACHE PATH "")
set(FREEIMAGE_INCLUDE_DIRS "${ROOT_DIR}inc/freeimage" CACHE PATH "")
set(FREEIMAGE_LIBRARIES "${ROOT_DIR}libs/mingw/freeimage" CACHE PATH "")
set(FREEIMAGE_LIBRARY "freeimage.lib" CACHE PATH "")
set(GLEW_INCLUDE_DIR "${ROOT_DIR}inc/gl" CACHE PATH "")
set(GLEW_LIBRARY "glew32" CACHE PATH "")
set(ASSIMP_LIBRARY "assimp" CACHE PATH "")
set(GTEST_LIBRARY "gtest" CACHE PATH "")