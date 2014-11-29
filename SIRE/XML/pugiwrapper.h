#ifndef PUGIWRAPPER_H
#define PUGIWRAPPER_H

#include "DesignPatterns/Multiton.h"
#include "mainapplication.h"

namespace SIRE
{
    namespace XML
    {
        class PugiWrapper;
        class PugiWrapper : Multiton<PugiWrapper>
        {
            friend class Multiton;
            friend class MainApplication;
        protected:
            PugiWrapper();
            virtual ~PugiWrapper();
        };
    }
}

#endif // PUGIWRAPPER_H
