#include"memory.h"
void mem::write(){
	if(rw_p== SC_LOGIC_0){
		b1 = ~b1; 
		if (b1 == false) {
			next_trigger(write_latency);
			b1 = !b1;
		}
		if (b1 == true) {
			my_mem[addr_line->read()] = data_in->read();
			//cout << "ADDRESS : " << addr_line->read() << "DATA : " << data_in->read() << endl;
		}
	}
}
void mem::read(){
	if(rw_p == SC_LOGIC_1){
		b2 = ~b2;
		if (b2 == false) {
			next_trigger(read_latency);
			b2 = !b2;
		}
		if (b2 == true) {
			data_out->write(my_mem[addr_line->read()]);
		}
		//cout << "ADDRESS" << addr_line->read() << "DATA WRITE" << my_mem[addr_line->read()] << endl;
	}
}
void mem::reset1(){
	if(reset){
		for(uint32_t i=0;i<memsize;i++){
			my_mem[i]= 0;
		}
	}
}