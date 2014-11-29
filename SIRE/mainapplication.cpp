#include "mainapplication.h"

using namespace SIRE;

MainApplication::MainApplication()
    : Multiton<MainApplication>()
{
}

MainApplication::~MainApplication()
{
    /* Delete our opengl context, destroy our window, and shutdown SDL */
    SDL_GL_DeleteContext(mainContext);
    SDL_DestroyWindow(mainWindow);
    SDL_Quit();
}

void MainApplication::sdldie(const char *msg)
{
    printf("%s: %s\n", msg, SDL_GetError());
    SDL_Quit();
    exit(1);
}

void MainApplication::checkSDLError(int line)
{
#ifndef NDEBUG
    const char *error = SDL_GetError();
    if (*error != '\0')
    {
        printf("SDL Error: %s\n", error);
        if (line != -1)
            printf(" + line: %i\n", line);
        SDL_ClearError();
    }
#endif
}

bool MainApplication::initialize(std::string path)
{
    this->path = path;

    XML::PugiWrapper *xmlwrapper = XML::PugiWrapper::getPtr("pugiwrapper");

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        sdldie("Unable to initialize SDL");
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    mainWindow = SDL_CreateWindow("SIRE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if(!mainWindow)
    {
        sdldie("Unable to create window");
        return false;
    }

    checkSDLError(__LINE__);
    mainContext = SDL_GL_CreateContext(mainWindow);
    checkSDLError(__LINE__);

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    return true;
}

void MainApplication::execute(std::string path)
{
    if(!initialize(path)){
        return;
    }

}
