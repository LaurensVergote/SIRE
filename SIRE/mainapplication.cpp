#include "mainapplication.h"

MainApplication::MainApplication()
{
}

MainApplication::~MainApplication()
{
}

bool MainApplication::initialize(std::string path)
{
    this->path = path;

    return true;
}

void MainApplication::execute(std::string path)
{
    if(!initialize(path)){
        return;
    }


}
