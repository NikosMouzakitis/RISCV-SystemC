all:
	g++ -I/home/nicko/implementations/systemc-2.3.3/include main_sc.cpp -o run-riscv-core -L/home/nicko/implementations/systemc-2.3.3/lib-linux64  -lsystemc  -fpermissive

view:
	gtkwave my_db.vcd

clean:
	rm my_db.vcd run-riscv-core
