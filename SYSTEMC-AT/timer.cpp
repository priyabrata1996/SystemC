#include "timer.h"
void time1::write1(){
	sc_bv<8> temp=addr;
	sc_bv<8> temp1=data_in;
	if(write_en && (temp.to_uint()==8 || temp.to_uint()==0)){
		register1[temp.to_uint()]=temp1.to_uint();
	}
}
void time1::read1(){
	sc_bv<8> temp=addr;
	if(read_en)
		data_out.write(register1[temp.to_uint()]);
}
void time1::increment(){
	if((register1[0] & 1)){
		if((register1[4]==register1[8]) && (register1[4]!=0)){
			register1[12]=1;
			register1[4]=register1[4]+1;
		}
		else if((register1[4]==255) && (register1[4]!=0)){
			register1[12]=2;
			register1[4]=0;
		}
		else{
			register1[4]=register1[4]+1;
			intr0.write(0);
			intr1.write(0);
		}
		if(register1[12] ==1){
			intr0.write(1);
			intr1.write(0);
			register1[12]=0;
		}
		else if(register1[12] ==2){
			intr0.write(0);
			intr1.write(1);
			register1[12]=0;
		}
	}
}
void time1::reset1(){
		register1[0]=0;
		register1[4]=0;
		register1[8]=0;
		register1[12]=0;
}