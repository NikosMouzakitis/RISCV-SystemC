#include "cpu.h"
#include <iostream>

/*   A simple RISCV cpu datapath emulation designed using SystemC.
 *   author: Mouzakitis Nikolaos (2023)	*/

using namespace std;
int sc_main(int argc, char * argv[])
{

	CPU cpu1("core1");
	
	sc_start(100,SC_NS); //start simulation for 100 nanoseconds.

	return 0;
}

