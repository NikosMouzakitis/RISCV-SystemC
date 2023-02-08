#include "cpu.h"
#include <iostream>

/*   A simple RISCV cpu datapath emulation designed using SystemC.
 *   author: Mouzakitis Nikolaos (2023)	*/

using namespace std;
int sc_main(int argc, char * argv[])
{

//	driver d1("driver");
	/* initialization*
		signals*/
	sc_signal <bool> reset_progcnt;
	reset_progcnt.write(0x0);
	sc_signal <bool> increment_pc;
	increment_pc.write(0x1);
	sc_signal <uint32_t> program_counter_out;
	program_counter_out.write(0x0);


	sc_clock clk("clk" ,10, SC_NS, 0.5);

	CPU cpu1("core1");
	cpu1.clock(clk);
	cpu1.reset_pc(reset_progcnt);
	cpu1.inc_pc(increment_pc);
	cpu1.pc_out_from_pc(program_counter_out);


	sc_start(100,SC_NS); //start simulation for 100 nanoseconds.

	return 0;
}

