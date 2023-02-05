#include "systemc.h"
#include <iostream>

SC_MODULE(CPU)
{
	//modules included in the RISC-V CPU.


	SC_CTOR(CPU) 
	{
		std::cout << "Cpu constructor" << endl;
	}

};

