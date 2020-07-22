#include<systemc.h>
#define buswidth 32
#define memsize 3200
const sc_time read_latency(2,SC_NS);
const sc_time write_latency(3, SC_NS);


SC_MODULE(mem){
	sc_in<uint32_t > addr_line{ "addr_line" };
	sc_in<uint32_t >data_in{ "data_in_tb" };
	sc_out<uint32_t >data_out{ "data_out_tb" };
	sc_in_resolved rw_p{ "rw_p" };
	sc_in<bool> reset{ "reset" };
	uint32_t my_mem[memsize];
	sc_signal<bool> b1{ "b1" }, b2{ "b2" };
	SC_CTOR(mem)
	{
		b1= true;
		b1 = true;

		SC_METHOD(read)
		sensitive<<rw_p;
		dont_initialize(); 
	
		SC_METHOD(write)
		sensitive<<rw_p;
		dont_initialize();
		
		SC_METHOD(reset1);
		sensitive<<reset;
		dont_initialize();
	}
	void read();
	void reset1();
	void write();
};