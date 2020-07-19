#include<systemc>
#include<time.h>
#include"mem_tb.h"
#include"memory.h"
SC_MODULE(mem_system){
	mem *m1=NULL;
	mem_tb *t1=NULL;
	sc_signal<sc_bv<buswidth> > addr_line_sig;
	sc_signal<sc_bv<buswidth> >data_in_sig;
	sc_signal<sc_bv<buswidth> >data_out_sig;
	sc_signal<bool > read_en_sig, write_en_sig;
	sc_signal<bool> reset_sig;
	SC_CTOR(mem_system){
		t1= new mem_tb("t1");
		t1->addr_line(addr_line_sig);
		t1->data_in(data_in_sig);
		t1->data_out(data_out_sig);
		t1->read_en(read_en_sig);
		t1->write_en(write_en_sig);
		t1->reset(reset_sig);
		
		m1= new mem("m1");
		m1->addr_line(addr_line_sig);
		m1->data_in(data_in_sig);
		m1->data_out(data_out_sig);
		m1->read_en(read_en_sig);
		m1->write_en(write_en_sig);
		m1->reset(reset_sig);
	}
	~mem_system(){
		delete t1;
		delete m1;
	}
};
mem_system *sys=NULL;
int sc_main(int argc, char *argv[]){
	clock_t start, end;
	double time_taken;
	start = clock();
	sys = new mem_system("sys");
 	sc_start(2000,SC_MS);
	sc_stop();
	end = clock();
	time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Wall clock time is : " << time_taken << endl;
	return 0;
}
		