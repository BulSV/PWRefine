#include <iostream>
#include <new>
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
    	try {
    		refineDriver = new ConsoleRefineDriver();
    	} catch (std::bad_alloc &ba) {
    		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    		return -1;
    	}
    }

    try {
    	refineDriver->info();
    	refineDriver->input();
    	refineDriver->driver();
    	refineDriver->output();
    } catch (std::bad_alloc &ba) {
    	std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    	return -1;
    } catch (DecodingException &e) {
    	std::cerr << e.getMessage() << "\nError letter is \"0x"
    			 << std::uppercase << std::hex
    			<< e.getErrorLetter() << "\"\n";
    }

    delete refineDriver;
    refineDriver = 0;

    std::cin.get();

    return 0;
}
