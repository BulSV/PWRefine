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
#include "Exceptions/emptyexception.h"

class ConsoleRefineDriver : public RefineDriver
{
    CountManager *itsCountManager;

    bool inputArmorCategory(InputChecker &inputChecker);
    bool inputArmorProperty(InputChecker &inputChecker);
    bool inputArmorRefineLevel(InputChecker &inputChecker);
    void armorCreator(std::string choiceCategory,
    		std::string property,
    		std::string refineLevel,
    		Armor *&armor);
    void inputArmors();
    REFINE_LEVEL intToRefineLevel(int refineLevel);
    void outputResults();
    void outputResults(int index);
    void refineInfo(REFINE refine);
    bool refineArmorNumber(InputChecker &inputChecker);
    bool refineStoneChoice(InputChecker &inputChecker);
    REFINE refineArmor(std::string stone, std::string armorNumber);
    bool refineContinue(InputChecker &inputChecker);
    void refining();
    char* cp1251to866(char *c) const;
    void headOutputResults();
    void detaleArmorOutputResults(int index);
    void tailOutputResults();
    bool distributorInput(InputChecker &inputChecker);
    void distributor();
    bool isEmptyCountManager() const throw(EmptyException);
    bool isStringEmpty(std::string str) const throw(EmptyException);
	void setArmorCategory(InputChecker& inputChecker);
	void setArmorProperty(InputChecker& inputChecker);
	void setArmorRefineLevel(InputChecker& inputChecker);

public:
    ConsoleRefineDriver();
    virtual ~ConsoleRefineDriver();
    virtual void info() const;
    virtual void input();
    virtual void driver();
    virtual void output();
};

#endif // CONSOLEREFINEDRIVER_H
