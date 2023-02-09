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
	init_read_main_mem.write(0x1); //initial value read_main_mem is set to '1' so the execution can start fetching instructions.
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

	/* instruction decoder */
	sc_signal<uint32_t> init_id_instruction;
	sc_signal<bool> init_id_op2_sel;
	sc_signal<sc_bv<10>> init_id_alu_ctl;
	sc_signal<sc_bv<12>> init_id_inst_imm;
	sc_signal<sc_bv<5>> init_id_inst_shamt;
	sc_signal<bool> init_id_imm_mux_sel;
	sc_signal<bool> init_id_reg_wrt;
	sc_signal<sc_bv<5>> init_id_inst19_15;
	sc_signal<sc_bv<5>> init_id_inst24_20;
	sc_signal<sc_bv<5>> init_id_inst11_7;

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

	/*bindings for instruction decoder*/
	cpu1.id_instruction(init_id_instruction);
	cpu1.id_op2_sel(init_id_op2_sel);
	cpu1.id_alu_ctl(init_id_alu_ctl);
	cpu1.id_inst_imm(init_id_inst_imm);
	cpu1.id_inst_shamt(init_id_inst_shamt);
	cpu1.id_imm_mux_sel(init_id_imm_mux_sel);
	cpu1.id_reg_wrt(init_id_reg_wrt);
	cpu1.id_inst19_15(init_id_inst19_15);
	cpu1.id_inst24_20(init_id_inst24_20);
	cpu1.id_inst11_7(init_id_inst11_7);

	std::cout << "##########################################################################" << endl;
	std::cout << "################           Simulation Start           ###################" << endl;
	std::cout << "##########################################################################" << endl << endl;
	


	sc_start(20,SC_NS); //start simulation.

	return 0;
}

