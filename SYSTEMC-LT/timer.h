#include "systemc.h"	
#include<map>
SC_MODULE(time1){
	sc_in<bool > reset;
	sc_in<sc_bv<8> > addr;
	sc_in<sc_bv<8> > data_in;
	sc_in<bool> write_en, read_en;
	sc_out<int > intr0;
	sc_out<int > intr1;
	sc_out<sc_bv<8> > data_out;
	double clk_period,last_simulation_time,disable_time,enable_time,last_clk;
	sc_event event_intr0,event_intr1,e;
	std::map<int,int > register1;
	SC_CTOR(time1)
	{
		last_simulation_time=0;
		enable_time=0;
		disable_time=0;
		clk_period = 20;
		register1[0]=0;
		register1[4]=0;
		register1[8]=0;
		register1[12]=0;
		SC_METHOD(reset1){
			sensitive<<reset;
			dont_initialize();
		}
		SC_METHOD(read1){
			sensitive<<read_en;
			dont_initialize();
		}
		SC_METHOD(write1){
			sensitive<< write_en;
			dont_initialize();
		}
		SC_METHOD(increment){
			sensitive<< event_intr0<<event_intr1;
			dont_initialize();
		}
		SC_METHOD(clk_cycle){
			sensitive<< e;
		}
	}
	void read1();
	void increment();
	void write1();
	void reset1();
	void clk_cycle();
};
