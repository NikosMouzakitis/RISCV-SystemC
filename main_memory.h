#include "systemc.h"
#include <iostream>

#define MEMORY_SIZE 0x1000

SC_MODULE(MainMemory) {
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_in<bool> rd;
  sc_in<bool> wr;
  sc_in<uint32_t> d_in;
  sc_in<uint32_t> address;
  sc_out<uint32_t> d_out;

  uint32_t mem[MEMORY_SIZE];

  void do_rd() {
    if (rd) {
	std::cout << "Main Memory read() from address: 0x" << std::hex <<  address << endl;
	std::cout << "Writing on d_out 0x" << std::hex << mem[address.read()] << endl;
	d_out.write(mem[address.read()]);
    }
  }

  void do_wr() {
    if (wr) {
      std::cout << "Main Memory write()" << endl;
      mem[address.read()] = d_in.read();
    }
  }
  void init_main_mem(void)
  {
	//addi   x11,x0 ,7
	mem[0x0] = 0x0700593;
	//addi   x12,x0 ,8
	mem[0x01] = 0x800613;	
  }

  SC_CTOR(MainMemory) {
    SC_METHOD(do_rd);
//    sensitive << clk.pos();
    sensitive << d_in << rst << rd << wr << address;
    SC_METHOD(do_wr);
    sensitive << d_in << rst << rd << wr << address;
//    sensitive << clk.pos();
    init_main_mem();
    std::cout << "Main Memory module 0x" << std::hex << MEMORY_SIZE <<" bytes created" << endl;

  }
};
