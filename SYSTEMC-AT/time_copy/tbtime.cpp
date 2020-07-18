#include "tbtime.h"
void tb::print_intr(){
		if(intr0.read())
			std::cout<<"Intr0 ( "<<sc_time_stamp()<<")"<<endl;
		else if(intr1.read())
			std::cout<<"Intr1 ( "<<sc_time_stamp()<<" )"<<endl;
}
void tb::print_timeval(){
	sc_bv<8> temp=data_out;
	std::cout<<temp.to_uint()<<endl;
}
	
void tb::test(){
	write_en.write(true);
	read_en.write(true);
	data_in.write((sc_bv<8>)135);	
	wait(18470,SC_NS);
	addr="00001100";
	wait(1520,SC_NS);
	addr="00011000";
	wait(10,SC_NS);
	read_en.write(false);
	wait(500,SC_NS);
	addr="00001010";
	wait(500,SC_NS);
	read_en.write(true);
	wait(8990,SC_NS);
	addr="00011000";
	wait(10,SC_NS);
	data_in.write((sc_bv<8>)200);
	wait(10,SC_US);
	write_en.write(false);
	wait(60,SC_US);
	write_en.write(true);
	wait(750,SC_NS);
	addr="00001010";
	wait(9250,SC_NS);
	write_en.write(false);
}