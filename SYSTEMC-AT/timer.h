#include "systemc.h"	
#include<map>
SC_MODULE(time1){
	sc_in<bool> clock;
	sc_in<bool > reset;
	sc_in<sc_bv<8> > addr;
	sc_in<sc_bv<8> > data_in;
	sc_in<bool> write_en, read_en;
	sc_out<int > intr0;
	sc_out<int > intr1;
	sc_out<sc_bv<8> > data_out;
	std::map<int,int > register1;
	SC_CTOR(time1){
		register1[0]=0;
		register1[4]=0;
		register1[8]=0;
		register1[12]=0;
		SC_METHOD(read1){
			sensitive<<read_en;
			dont_initialize();
		}
		SC_METHOD(write1){
			sensitive<< write_en;
			dont_initialize();
		}
		SC_METHOD(increment){
			sensitive<< clock.pos();
			dont_initialize();
		}
		SC_METHOD(reset1){
			sensitive<<reset;
			dont_initialize();
		}
	}
	void read1();
	void increment();
	void write1();
	void reset1();
};
