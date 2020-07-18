#include "timer.h"
void time::read(){
	sc_bv<8>temp=addr;
	if(write_en)
		data_out.write((sc_bv<8>)register1[4]);
}
void time::change_timer_cmp(){
	sc_bv<8> temp;
	temp=data_in;
	register1[8]=temp.to_uint();
}
void time::increament(){
	if((register1[0] & 1) && read_en){
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
		if(register1[12] ==1 && write_en){
			intr0.write(1);
			intr1.write(0);
			register1[12]=0;
		}
		else if(register1[12] ==2 && write_en){
			intr0.write(0);
			intr1.write(1);
			register1[12]=0;
		}
	}
}
