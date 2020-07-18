#include "tbtime.h"
void tb::print_intr(){
		if(intr0.read() && print_message)
			std::cout<<"Intr0 ( "<<sc_time_stamp()<<")"<<endl;
		else if(intr1.read()&& print_message)
			std::cout<<"Intr1 ( "<<sc_time_stamp()<<" )"<<endl;
}	
void tb::test(){
	print_message=true;
	addr.write((sc_bv<8>)0);
	data_in.write((sc_bv<8>)0);
	wait(SC_ZERO_TIME);
	write_en.write(true);
	wait(SC_ZERO_TIME);
	write_en.write(false);
	
	addr.write((sc_bv<8>)4);
	data_in.write((sc_bv<8>)0);
	wait(SC_ZERO_TIME);
	write_en.write(true);
	wait(SC_ZERO_TIME);
	write_en.write(false);
	
	addr.write((sc_bv<8>)8);
	data_in.write((sc_bv<8>)0);
	wait(SC_ZERO_TIME);
	write_en.write(true);
	wait(SC_ZERO_TIME);
	write_en.write(false);
	
	addr.write((sc_bv<8>)12);
	data_in.write((sc_bv<8>)0);
	wait(SC_ZERO_TIME);
	write_en.write(true);
	wait(SC_ZERO_TIME);
	write_en.write(false);
	
	addr.write((sc_bv<8>)0);
	data_in.write((sc_bv<8>)7);
	wait(SC_ZERO_TIME);
	write_en.write(true);
	wait(SC_ZERO_TIME);
	write_en.write(false);
	
	wait(SC_ZERO_TIME);
	addr.write((sc_bv<8>)8);
	data_in.write((sc_bv<8>)135);
	wait(SC_ZERO_TIME);
	write_en.write(true);
	wait(SC_ZERO_TIME);
	write_en.write(false);
	
	wait(18470,SC_NS);
	addr.write((sc_bv<8>)4);
	wait(SC_ZERO_TIME);
	read_en.write(true);
	wait(request_update());
	sc_bv<8>temp3=data_out;
	std::cout<<temp3.to_uint()<<endl;
	read_en.write(false);
	
	wait(1520,SC_NS);
	addr.write((sc_bv<8>)4);
	wait(SC_ZERO_TIME);
	read_en.write(true);
	wait(data_out.default_event());
	temp3=data_out;
	std::cout<<temp3.to_uint()<<endl;
	read_en.write(false);
	
	wait(10,SC_NS);	
	addr.write((sc_bv<8>)0);
	data_in.write((sc_bv<8>)0);
	wait(SC_ZERO_TIME);
	write_en.write(true);
	wait(SC_ZERO_TIME);
	write_en.write(false);
	
	wait(500,SC_NS);
	addr.write((sc_bv<8>)4);
	wait(SC_ZERO_TIME);
	read_en.write(true);
	wait(data_out.default_event());
	temp3=data_out;
	std::cout<<temp3.to_uint()<<endl;
	read_en.write(false);
	
	wait(500,SC_NS);
	addr.write((sc_bv<8>)0);
	data_in.write((sc_bv<8>)7);
	wait(SC_ZERO_TIME);
	write_en.write(true);
	wait(SC_ZERO_TIME);
	write_en.write(false);
	
	wait(8990,SC_NS);
	addr.write((sc_bv<8>)4);
	wait(SC_ZERO_TIME);
	read_en.write(true);
	wait(data_out.default_event());
	temp3=data_out;
	std::cout<<temp3.to_uint()<<endl;
	read_en.write(false);
	
	wait(10,SC_NS);
	addr.write((sc_bv<8>)8);
	data_in.write((sc_bv<8>)200);
	wait(SC_ZERO_TIME);
	write_en.write(true);
	wait(SC_ZERO_TIME);
	write_en.write(false);
	
	wait(10,SC_US);
	print_message=false;
	
	wait(60,SC_US);
	print_message=true;
	
	wait(750,SC_NS);
	addr.write((sc_bv<8>)4);
	wait(SC_ZERO_TIME);
	read_en.write(true);
	wait(data_out.default_event());
	temp3=data_out;
	std::cout<<temp3.to_uint()<<endl;
	read_en.write(false);
	
	wait(9250,SC_NS);
	print_message=false;
}