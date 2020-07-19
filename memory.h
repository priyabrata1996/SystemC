#include<systemc.h>
#define buswidth 32
#define memsize 3200
const sc_time read_latency(2,SC_NS);
const sc_time write_latency(3, SC_NS);


SC_MODULE(mem){
	sc_in<sc_bv<buswidth> > addr_line;
	sc_in<sc_bv<buswidth> >data_in;
	sc_out<sc_bv<buswidth> >data_out;
	sc_in<bool > read_en, write_en;
	sc_in<bool> reset;
	sc_bv<buswidth> my_mem[memsize];
	sc_signal<bool> b1,b2;
	SC_CTOR(mem){
		b1= true;
		b1 = true;
		SC_METHOD(read)
		sensitive<<read_en;
		dont_initialize(); 
	
		SC_METHOD(write){
			sensitive<<write_en;
			dont_initialize();
		}
		SC_METHOD(reset1);
		sensitive<<reset;
		dont_initialize();
	}
	void read();
	void reset1();
	void write();
};