#include "timer.h"
void time1::read1(){
	sc_bv<8> temp=addr;
	double current_time=sc_simulation_time();
	if((register1[0] & 1)){
		register1[4]=(current_time-last_simulation_time-enable_time+disable_time)/clk_period;
	}
	else
		register1[4]=(disable_time-last_simulation_time)/clk_period;
	if(read_en)
		data_out.write(register1[temp.to_uint()]);
}
void time1::write1(){
	sc_bv<8> temp=addr;
	sc_bv<8> temp1=data_in;
	if(write_en && (temp.to_uint()==8 || temp.to_uint()==0)){
		register1[temp.to_uint()]=temp1.to_uint();
		if((temp.to_uint()==0) && register1[temp.to_uint()]==0){
			disable_time=sc_simulation_time();
			e.cancel();
		}
		else if((temp.to_uint()==0) && register1[temp.to_uint()]==7){
			enable_time=sc_simulation_time();
			int time2=(256-((disable_time-last_clk)/clk_period))*20;
			event_intr1.notify(time2,SC_NS);
			e.notify(time2,SC_NS);
		}
	}
}
void time1::clk_cycle(){
	int temp1=clk_period*256;
	int temp;
	if(sc_simulation_time()==0){
		temp=clk_period*135;
	}
	else
		temp=clk_period*register1[8];
	event_intr0.notify(temp,SC_NS);
	event_intr1.notify(temp1,SC_NS);
	e.notify(5120,SC_NS);
	last_clk=sc_simulation_time();
}

void time1::increment(){
	double current_time=sc_simulation_time();
	if((register1[0] & 1)){
		register1[4]=(current_time-last_simulation_time+disable_time-enable_time)/clk_period;
		if((register1[4]==register1[8])){
			register1[12]=1;
			intr0.write(1);
			intr1.write(0);
		}
		else if((register1[4]==256)){
			register1[12]=2;
			register1[4]=0;
			last_simulation_time=current_time+disable_time-enable_time;
			intr0.write(0);
			intr1.write(1);
		}
	}
}
void time1::reset1(){
	register1[0]=0;
	register1[4]=0;
	register1[8]=0;
	register1[12]=0;
}