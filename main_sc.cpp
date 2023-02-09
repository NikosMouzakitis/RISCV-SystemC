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

	/* register file */
	sc_signal <sc_bv<5>> init_rf_rs1;	
	sc_signal <sc_bv<5>> init_rf_rs2;	
	sc_signal <sc_bv<5>> init_rf_rd;	
	sc_signal <bool> init_rf_write;
	sc_signal <uint32_t> init_rf_din;
	sc_signal<uint32_t> init_rf_reg_data1;
	sc_signal<uint32_t> init_rf_reg_data2;



	/* universal clock */
	std::cout << "Set clock period: 10 nanosecods\n" << endl;
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
	/*bindings for register file*/	
	cpu1.rf_rs1(init_rf_rs1);
	cpu1.rf_rs2(init_rf_rs2);
	cpu1.rf_rd(init_rf_rd);
	cpu1.rf_write(init_rf_write);
	cpu1.rf_din(init_rf_din);
	cpu1.rf_reg_data1(init_rf_reg_data1);
	cpu1.rf_reg_data2(init_rf_reg_data2);
	std::cout << "Simulation Start" << endl;
	sc_start(200,SC_NS); //start simulation.

	return 0;
}

