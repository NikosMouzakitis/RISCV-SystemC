#include "systemc.h"
#include "program_counter.h"
#include <iostream>
#include "main_memory.h"

SC_MODULE(CPU)
{
	/* declarations of
	 * modules included in 
	 * the RISC-V CPU*/
	
	ProgramCounter pc;
	MainMemory main_mem;	

	/*  Definition of the inputs for::	
	*/	
		// program counter
	sc_in_clk clock;
	sc_in<bool> reset_pc;
	sc_in<bool> inc_pc;
	sc_out<uint32_t> pc_out_from_pc;
	
	//main memory
	sc_in<bool> reset_main_mem;
	sc_in<bool> write_main_mem;
	sc_in<bool> read_main_mem;
	sc_in<uint32_t> data_in_main_mem;
	sc_in<uint32_t> address_main_mem;
	sc_out<uint32_t> data_out_main_mem;


	void debug_test(void)
	{
		std::cout << "PC: " << std::hex << pc_out_from_pc << endl;

	}

	SC_CTOR(CPU) : pc("program_counter"), main_mem("main_memory")
	{
		/*bind program counter*/
		pc.clock(clock);
		pc.reset(reset_pc);
		pc.inc(inc_pc);
		pc.pc_out(pc_out_from_pc);

		/*bind main memory*/
		main_mem.clk(clock);
		main_mem.rst(reset_main_mem);
		main_mem.rd(read_main_mem);
		main_mem.wr(write_main_mem);
		main_mem.d_in(data_in_main_mem);
		main_mem.address(address_main_mem);
		main_mem.d_out(data_out_main_mem);

		std::cout << "Cpu constructor" << endl;

		SC_METHOD(debug_test);
		sensitive << clock.pos() ;

	}

};

