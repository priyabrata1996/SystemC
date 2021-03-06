#include<iostream>
#include<time.h>
#include "timer.h"
#include "tbtime.h"

SC_MODULE(upcounter){
	time1 *t1=NULL;
	tb *tb1=NULL;
	sc_signal<sc_bv<8> > sig_addr,sig_data_in, sig_data_out;
	sc_signal<int> sig_intr0, sig_intr1;
	sc_signal<bool> sig_reset;
	sc_signal<bool> write_en_sig, read_en_sig;
	SC_CTOR(upcounter)
	{	
		t1=new time1("t1");
		t1->addr(sig_addr);
		t1->data_in(sig_data_in);
		t1->reset(sig_reset);
		t1->intr0(sig_intr0);
		t1->intr1(sig_intr1);
		t1->data_out(sig_data_out);
		t1->read_en(read_en_sig);
		t1->write_en(write_en_sig);
		
		tb1= new tb("tb1");
		tb1->addr(sig_addr);
		tb1->data_in(sig_data_in);
		tb1->reset(sig_reset);
		tb1->intr0(sig_intr0);
		tb1->intr1(sig_intr1);
		tb1->data_out(sig_data_out);
		tb1->read_en(read_en_sig);
		tb1->write_en(write_en_sig);
	}
	~upcounter(){
		delete t1;
		delete tb1;
	}
};

upcounter *up=NULL;
int sc_main(int argc, char **argv){
	clock_t start, end;
	double time_taken;
	start = clock();	
	up=new upcounter("up");
	sc_start(100,SC_MS);
	sc_stop;
	end = clock();
	time_taken = double(end - start)/ double(CLOCKS_PER_SEC);
	cout<<"Wall clock time is"<<time_taken<<endl;
	return 0;
}