#include<iostream>
#include "systemc.h"	

SC_MODULE(tb){
	sc_in<bool> clock;
	sc_out<bool > reset;
	sc_out<sc_bv<8> > addr;
	sc_out<sc_bv<8> > data_in;
	sc_out<bool> write_en, read_en;
	sc_in<int > intr0;
	sc_in<int > intr1;
	sc_in<sc_bv<8> > data_out;
	int print_flag;
	SC_CTOR(tb){
		print_flag=0;
		SC_THREAD(test);
		SC_METHOD(print_intr);
		sensitive<<intr0<<intr1;
		SC_METHOD(print_timeval);
		sensitive<<data_out;
		dont_initialize();
	}
	void test();
    void print_intr();
	void print_timeval();
};
