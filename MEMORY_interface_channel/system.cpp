#include<systemc>
#include<time.h>
#include"mem_tb.h"
#include"memory.h"
#include"bus.h"
SC_MODULE(mem_system) {
	sc_signal<uint32_t > addr_line_sig{ "addr_line_sig" };
	sc_signal<uint32_t > data_in_sig{ "data_line_sig" };
	sc_signal<uint32_t > data_out_sig{ "data_line_sig" };
	sc_signal_resolved rw_s { "rw_s" };
	sc_signal<bool> reset_sig { "reset_sig" };
	mem_tb t1 { "t1" };
	bus_channel bc{ "bc" };
	mem m1{"m1"};
	SC_CTOR(mem_system){
		t1.mem_socket_tb (bc);
		bc.addr_line_tb (addr_line_sig);
		bc.data_in_tb (data_in_sig);
		bc.data_out_tb(data_out_sig);
		bc.rw_p (rw_s);
		t1.reset (reset_sig);

		m1.addr_line (addr_line_sig);
		m1.data_in(data_in_sig);
		m1.data_out(data_out_sig);
		m1.rw_p (rw_s);	
		m1.reset (reset_sig);
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
		