#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <string>
#include "DesignPatterns/Multiton.h"

class MainApplication : public Multiton<MainApplication>
{
public:
    void execute(std::string path);

protected:
    MainApplication();
    ~MainApplication();

private:

    bool initialize(std::string path);

    std::string path;
};

#endif // MAINAPPLICATION_H
