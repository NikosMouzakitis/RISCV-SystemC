#include "cpu.h"
#include <iostream>

/*   A simple RISCV cpu datapath emulation designed using SystemC.
 *   author: Mouzakitis Nikolaos (2023)	*/

using namespace std;
int sc_main(int argc, char * argv[])
{

	/* initialization signals*/

	/* program counter module */
	sc_signal <bool> init_reset_progcnt;
	init_reset_progcnt.write(0x0);
	sc_signal <bool> init_increment_pc;
	init_increment_pc.write(0x1);
	sc_signal <uint32_t> init_program_counter_out;
	init_program_counter_out.write(0x0);

	/* main memory module */
	sc_signal<bool> init_reset_main_mem;
	init_reset_main_mem.write(0x0);
	sc_signal<bool> init_write_main_mem;
	init_write_main_mem.write(0x0);
	sc_signal<bool> init_read_main_mem;
	init_read_main_mem.write(0x0);
	sc_signal<uint32_t> init_data_in_main_mem;
	sc_signal<uint32_t> init_address_main_mem;
	sc_signal<uint32_t> init_data_out_main_mem;



	/* universal clock */
	sc_clock clk("clk" ,10, SC_NS, 0.5);
	/*risc-v cpu core */	
	CPU cpu1("core1");
	cpu1.clock(clk);

	/*bindings for program counter module*/
	cpu1.reset_pc(init_reset_progcnt);
	cpu1.inc_pc(init_increment_pc);
	cpu1.pc_out_from_pc(init_program_counter_out);

	/*bindings for main memory module */
	cpu1.reset_main_mem(init_reset_main_mem);
	cpu1.write_main_mem(init_write_main_mem);
	cpu1.read_main_mem(init_read_main_mem);
	cpu1.data_in_main_mem(init_data_in_main_mem);
	cpu1.address_main_mem(init_address_main_mem);
	cpu1.data_out_main_mem(init_data_out_main_mem);

	sc_start(1000,SC_NS); //start simulation for 100 nanoseconds.

	return 0;
}

