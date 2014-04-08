#include <iostream>
#include "refinedriver.h"
#include "consolerefinedriver.h"

int main(int argc, char **argv)
{
    RefineDriver *refineDriver = 0;

    if(argc == 2 && *argv[1] == '-' && *(++argv[1]) == 'g')
    {
        // TODO Gui
    	std::cout << "GUI not yet\n";

    	return 0;
    }
    else
    {
        refineDriver = new ConsoleRefineDriver();
    }

    refineDriver->info();
    refineDriver->input();
    refineDriver->driver();
    refineDriver->output();

    return 0;
}
