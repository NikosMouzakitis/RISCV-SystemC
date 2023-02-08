#include "systemc.h"

SC_MODULE(RegisterFile)
{
	sc_in_clk clk;
	sc_in <sc_bv<5>> rs1;	
	sc_in <sc_bv<5>> rs2;	
	sc_in <sc_bv<5>> rd;	
	sc_in <bool> write;
	sc_in <uint32_t> din;
	sc_out<uint32_t> reg_data1;
	sc_out<uint32_t> reg_data2;

	/* our set of registers */
	uint32_t x0 = 0;
	uint32_t x1;
	uint32_t x2;
	uint32_t x3;
	uint32_t x4;
	uint32_t x5;
	uint32_t x6;
	uint32_t x7;
	uint32_t x8;
	uint32_t x9;
	uint32_t x10;
	uint32_t x11;
	uint32_t x12;
	uint32_t x13;
	uint32_t x14;
	uint32_t x15;
	uint32_t x16;
	uint32_t x17;
	uint32_t x18;
	uint32_t x19;
	uint32_t x20;
	uint32_t x21;
	uint32_t x22;
	uint32_t x23;
	uint32_t x24;
	uint32_t x25;
	uint32_t x26;
	uint32_t x27;
	uint32_t x28;
	uint32_t x29;
	uint32_t x30;
	uint32_t x31;

	uint32_t * prf[32];



	void UpdateRegisterFile(void)
	{
		return;
	}	
	void dump_regs(void)
	{

		std::cout << "Printing register file" << endl;
		for(int i = 0; i < 32; i++)
			std::cout << "$" << std::dec << i << " : " << std::hex << *prf[i] << endl;
	}	

	

	SC_CTOR(RegisterFile) {
	
		//* fill the pointer array for debugging.
		prf[0] = &x0;
		prf[1] = &x1;
		prf[2] = &x2;
		prf[3] = &x3;
		prf[4] = &x4;
		prf[5] = &x5;
		prf[6] = &x6;
		prf[7] = &x7;
		prf[8] = &x8;
		prf[9] = &x9;
		prf[10] = &x10;
		prf[11] = &x11;
		prf[12] = &x12;
		prf[13] = &x13;
		prf[14] = &x14;
		prf[15] = &x15;
		prf[16] = &x16;
		prf[17] = &x17;
		prf[18] = &x18;
		prf[19] = &x19;
		prf[20] = &x20;
		prf[21] = &x21;
		prf[22] = &x22;
		prf[23] = &x23;
		prf[24] = &x24;
		prf[25] = &x25;
		prf[26] = &x26;
		prf[27] = &x27;
		prf[28] = &x28;
		prf[29] = &x29;
		prf[30] = &x30;
		prf[31] = &x31;

		/*init regs to 0.*/		
		for(int i = 1; i < 32; i++)
			*(prf[i]) = 0;

		std::cout << "Register File module created" << endl;
		dump_regs();	

		SC_METHOD(UpdateRegisterFile);
		sensitive << clk.pos();	

	}

};
