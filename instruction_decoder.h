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

	/*decode() creates all the signals necessary to drive the correct operation of the processor. */
	void decode(void)
	{
		uint32_t fetched;
		uint32_t result;
		

		/* TO DO *
		 * First check for what kind is
		 * the instruction prior to assigning
		 * signals.*/

		fetched = instruction.read();	
		std::cout << "InstructionDecoder runs." << endl;	
		std::cout << "Fetched instruction: " << std::hex << fetched << endl;	

		//creating signal inst11_7	
		result = (fetched & 0b111110000000) >> 7;	
		inst11_7.write(result);
		std::cout << "inst11_7 : " << std::hex << inst11_7 << endl;
		//creating signal inst24_20
		result = (fetched & 0x01f00000) >> 20;
		inst24_20.write(result);
		std::cout << "inst24_20: " << std::hex << inst24_20 << endl;
		//creation of signal inst19_15
		result = (fetched & 0xf8000) >> 15;	
		inst19_15.write(result);
		std::cout << "inst19_15 : " << std::hex << inst19_15 << endl;

		


		return;
	}

	SC_CTOR(InstructionDecoder) {
		
		SC_METHOD(decode);
		sensitive << clk.pos();	
		std::cout << "Instruction Decoder initialized" << endl;
	}
};
