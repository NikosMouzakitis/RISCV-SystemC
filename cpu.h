#include "systemc.h"
#include "program_counter.h"
#include <iostream>
#include "main_memory.h"
#include "register_file.h"
#include "instruction_decoder.h"

SC_MODULE(CPU)
{
	/* declarations of
	 * modules included in 
	 * the RISC-V CPU*/
	
	ProgramCounter pc;
	MainMemory main_mem;	
	InstructionDecoder id;
	RegisterFile rf;

	/*  Definition of the inputs for::	
	*/	
	//clock
	sc_in_clk clock;

	// program counter
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
	
	//instruction decoder
	
	sc_in<uint32_t> id_instruction;
	sc_out<bool> id_op2_sel;
	sc_out<sc_bv<10>> id_alu_ctl;
	sc_out<sc_bv<12>> id_inst_imm;
	sc_out<sc_bv<5>> id_inst_shamt;
	sc_out<bool> id_imm_mux_sel;
	sc_out<bool> id_reg_wrt;
	sc_out<sc_bv<5>> id_inst19_15;
	sc_out<sc_bv<5>> id_inst24_20;
	sc_out<sc_bv<5>> id_inst11_7;

	//register file//	
	sc_in <sc_bv<5>> rf_rs1;	
	sc_in <sc_bv<5>> rf_rs2;	
	sc_in <sc_bv<5>> rf_rd;	
	sc_in <bool> rf_write;
	sc_in <uint32_t> rf_din;
	sc_out<uint32_t> rf_reg_data1;
	sc_out<uint32_t> rf_reg_data2;


	void debug_test(void)
	{
		std::cout << "[" << sc_time_stamp() << "] PC: " << std::hex << pc_out_from_pc << endl;

	}

	SC_CTOR(CPU) : pc("program_counter"), main_mem("main_memory"), rf("register_file") , id("instruction_decoder")
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
		main_mem.address(pc.pc_out);
		main_mem.d_out(data_out_main_mem);
	
		/*bind instruction decoder*/	
		id.clk(clock);
		id.instruction(main_mem.d_out);
		id.op2_sel(id_op2_sel);
		id.alu_ctl(id_alu_ctl);
		id.inst_imm(id_inst_imm);
		id.inst_shamt(id_inst_shamt);
		id.imm_mux_sel(id_imm_mux_sel);
		id.reg_wrt(id_reg_wrt);
		id.inst19_15(id_inst19_15);
		id.inst24_20(id_inst24_20);
		id.inst11_7(id_inst11_7);

		/*bind register file*/
		rf.clk(clock);
		rf.rs1(rf_rs1);
		rf.rs2(rf_rs2);
		rf.rd(rf_rd);
		rf.write(rf_write);
		rf.din(rf_din);
		rf.reg_data1(rf_reg_data1);
		rf.reg_data2(rf_reg_data2);

		std::cout << "Cpu constructor" << endl;
		sc_trace_file *tf = sc_create_vcd_trace_file("my_db");
		sc_trace(tf,clock,"Clock");
		sc_trace(tf,reset_pc,"ResetPC");
		sc_trace(tf,inc_pc,"IncPC");
		sc_trace(tf,pc_out_from_pc,"pc_out_from_pc");
		sc_trace(tf,id_inst19_15,"inst19_16");
		sc_trace(tf,id_inst11_7,"inst11_7");
		sc_trace(tf,id_inst24_20,"inst24_20");
		

		SC_METHOD(debug_test);
		sensitive << clock.pos() ;

	}

};

