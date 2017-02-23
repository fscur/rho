#pragma once
#include <rho.h>

class fileUtils
{
private:
    fileUtils(){ };
    ~fileUtils(){ };
public:
    static void getDirectoryFromPath(const char* fullPath, char* directory);
};