#include"memory.h"
void mem::write(){
	if(write_en ){
		b1 = ~b1;
		sc_bv<buswidth> temp = addr_line.read();
		sc_bv<buswidth> temp1 = data_in.read();
		if (b1 == false) {
			next_trigger(3, SC_NS);
			b1 = !b1;
		}
		if (b1 == true) {
			my_mem[temp.to_uint()] = data_in;
			//cout << "ADDRESS : " << temp.to_int() << "DATA : " << temp1.to_int() << endl;
		}
	}
}
void mem::read(){
	if(read_en){
		b2 = ~b2;
		sc_bv<buswidth> temp = addr_line;
		if (b2 == false) {
			next_trigger(2, SC_NS);
			b2 = !b2;
		}
		if (b2 == true) {
			data_out.write(my_mem[temp.to_int()]);
		}
		//cout << "ADDRESS" << temp.to_uint() << "DATA WRITE" << my_mem[temp.to_int()].to_uint() << endl;
	}
}
void mem::reset1(){
	if(reset){
		for(int i=0;i<memsize;i++){
			my_mem[i]= 0;
		}
	}
}