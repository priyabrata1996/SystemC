#include<systemc.h>
SC_MODULE(testbench1){
  sc_out<int > a,b;
  sc_in<int > y;
  sc_signal<int> temp;
  SC_CTOR(testbench1){
    SC_THREAD(origin);
	SC_METHOD(print1);
	  sensitive << y;
  }
  void origin(){  
    a.write(0);
   	b.write(0);   
	////////////////////
	wait(5,SC_NS);
    a.write(5);
    b.write(0);
    ////////////////////
    wait(3,SC_NS);
    a.write(5);
    b.write(10);
    ///////////////////////
    wait(7,SC_NS);
    a.write(7);
    b.write(8);
    ////////////////////////
  }
  void print1(){
	  std::cout<< y <<' ' << sc_time_stamp() <<std::endl;
  }
    sc_stop();
};