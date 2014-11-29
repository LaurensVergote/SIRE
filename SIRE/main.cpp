#include <string>
#include "mainapplication.h"

int main(int argc, char *argv[])
{
    std::string arg0 = argv[0];
    size_t sep = arg0.find_last_of("\\/");
    std::string path;
    if(sep != std::string::npos)
        path = arg0.substr(0, sep+1);

    SIRE::MainApplication* app = SIRE::MainApplication::getPtr("main");
    app->execute(path);
    SIRE::MainApplication::destroyAllInstances();
    return 0;
}

