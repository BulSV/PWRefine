#ifndef CONSOLEREFINEDRIVER_H
#define CONSOLEREFINEDRIVER_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include "refinedriver.h"
#include "refine.h"
#include "countmanager.h"
#include "armor.h"
#include "miragecelestone.h"
#include "tienkangstone.h"
#include "tishastone.h"
#include "chienkunstone.h"
#include "catalyzerstone.h"
#include "inputchecker.h"

class ConsoleRefineDriver : public RefineDriver
{
    CountManager *itsCountManager;

    void inputArmors();
    REFINE_LEVEL intToRefineLevel(int refineLevel);
    void outputResults();
    void outputResults(int index);
    void refineInfo(REFINE refine);
    void refining();
    char* cp1251to866(char *c) const;
    void headOutputResults();
    void detaleArmorOutputResults(int index);
    void tailOutputResults();
    void distributor();
    int stoi(const char *str);

public:
    ConsoleRefineDriver();
    virtual ~ConsoleRefineDriver();
    virtual void info() const;
    virtual void input();
    virtual void driver();
    virtual void output();
};

#endif // CONSOLEREFINEDRIVER_H
