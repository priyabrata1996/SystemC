#include "systemc.h"	
#include<map>
SC_MODULE(time){
	sc_in<bool> clock;
	sc_in<bool > reset;
	sc_in<sc_bv<8> > addr;
	sc_in<sc_bv<8> > data_in;
	sc_in<bool> write_en, read_en;
	sc_out<int > intr0;
	sc_out<int > intr1;
	sc_out<sc_bv<8> > data_out;
	std::map<int,int > register1;
	SC_CTOR(time){
		register1[0]=7;
		register1[4]=0;
		register1[8]=0;
		register1[12]=0;
		SC_METHOD(read){
			sensitive << addr;
			dont_initialize();
		}
		SC_METHOD(change_timer_cmp){
			sensitive<< data_in;
			dont_initialize();
		}
		SC_METHOD(increament);
		sensitive<<clock.pos();
		dont_initialize();
	}
	void read();
	void change_timer_cmp();
	void increament();
};
