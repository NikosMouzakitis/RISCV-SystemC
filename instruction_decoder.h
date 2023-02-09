#include "systemc.h"
#include <iostream>

SC_MODULE(InstructionDecoder) {
	
	sc_in<bool> clk;
	sc_in<uint32_t> instruction;
	sc_out<bool> op2_sel;
	sc_out<sc_bv<10>> alu_ctl;
	sc_out<sc_bv<12>> inst_imm;
	sc_out<sc_bv<5>> inst_shamt;
	sc_out<bool> imm_mux_sel;
	sc_out<bool> reg_wrt;
	sc_out<sc_bv<5>> inst19_15;
	sc_out<sc_bv<5>> inst24_20;
	sc_out<sc_bv<5>> inst11_7;
	

	void decode(void)
	{
		uint32_t fetched;
		fetched = instruction.read();	
		std::cout << "InstructionDecoder runs." << endl;	
		std::cout << "Fetched instruction: " << std::hex << fetched << endl;	
		
		return;
	}

	SC_CTOR(InstructionDecoder) {
		
		SC_METHOD(decode);
		sensitive << clk.pos();	
		std::cout << "Instruction Decoder initialized" << endl;
	}
};
