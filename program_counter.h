#include "systemc.h"
#include <iostream>

//program counter module.

SC_MODULE(ProgramCounter) {

   sc_in_clk clock;
   sc_in<bool> reset;
   sc_in<bool> inc;
   sc_out<uint32_t> pc_out;
   uint32_t pc;

   void count() {

      if (reset.read() == 1) {
         pc = 0;
      } else if (inc.read() == 1) {
         pc = pc + 1;
	 std::cout << "incrementing PC" << endl;
      }
      
      pc_out.write(pc);

   }

   SC_CTOR(ProgramCounter) {
      
      SC_METHOD(count);

      sensitive << clock.pos();
      std::cout << "Program Counter module created" << endl;
      std::cout << "PC at init time is: " << std::hex << pc << endl;
   }
};


