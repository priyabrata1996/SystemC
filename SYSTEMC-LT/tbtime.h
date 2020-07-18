#include<iostream>
#include "systemc.h"	

SC_MODULE(tb){
	sc_out<bool > reset;
	sc_out<sc_bv<8> > addr;
	sc_out<sc_bv<8> > data_in;
	sc_out<bool> write_en, read_en;
	sc_in<int > intr0;
	sc_in<int > intr1;
	sc_in<sc_bv<8> > data_out;
	bool print_message;
	sc_signal<bool> read_print;
	SC_CTOR(tb){
		print_message=false;
		SC_THREAD(test);
		SC_METHOD(print_intr);
		sensitive<<intr0<<intr1;
	}
	void test();
    void print_intr();
};
