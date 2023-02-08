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
      d_out.write(mem[address.read()]);
    }
  }

  void do_wr() {
    if (wr) {
      mem[address.read()] = d_in.read();
    }
  }

  SC_CTOR(MainMemory) {
    SC_METHOD(do_rd);
    sensitive << clk.pos();
    SC_METHOD(do_wr);
    sensitive << clk.pos();

    std::cout << "Main Memory module 0x" << std::hex << MEMORY_SIZE <<" bytes created" << endl;
  }
};
