#ifndef CONSOLEREFINEDRIVER_H
#define CONSOLEREFINEDRIVER_H

#include "refinedriver.h"
#include "refine.h"
#include "counthandler.h"

class ConsoleRefineDriver : public RefineDriver
{
    Refine *itsRefine;
    CountHandler *itsCountHandler;
public:
    ConsoleRefineDriver();
    virtual ~ConsoleRefineDriver();
    virtual void info() const;
    virtual void input();
    virtual void driver();
};

#endif // CONSOLEREFINEDRIVER_H
