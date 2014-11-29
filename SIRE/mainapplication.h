#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "StdAfx.h"
#include "DesignPatterns/Multiton.h"
#include "XML/pugiwrapper.h"

namespace SIRE
{
    class MainApplication;
    class MainApplication : public Multiton<MainApplication>
    {
        friend class Multiton;
    public:
        void execute(std::string path);

    protected:
        MainApplication();
        virtual ~MainApplication();

    private:

        void sdldie(const char *msg);
        void checkSDLError(int line = -1);
        bool initialize(std::string path);

        SDL_Window *mainWindow;
        SDL_GLContext mainContext;
        std::string path;
    };
}
#endif // MAINAPPLICATION_H
