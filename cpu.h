#include "systemc.h"
#include "program_counter.h"
#include <iostream>
//#include "main_memory.h"

SC_MODULE(CPU)
{
	/* declarations of
	 * modules included in 
	 * the RISC-V CPU*/
	
	ProgramCounter pc;

	/*  Definition of the inputs for::	
	*/	
		// program counter
	sc_in_clk clock;
	sc_in<bool> reset_pc;
	sc_in<bool> inc_pc;
	sc_out<uint32_t> pc_out_from_pc;


	void debug_test(void)
	{
		std::cout << "PC: " << std::hex << pc_out_from_pc << endl;

	}

	SC_CTOR(CPU) : pc("program counter")
	{
		pc.clock(clock);
		pc.reset(reset_pc);
		pc.inc(inc_pc);
		pc.pc_out(pc_out_from_pc);

		std::cout << "Cpu constructor" << endl;

		SC_METHOD(debug_test);
		sensitive << clock.pos() ;

	}

};

