#include<systemc.h>
SC_MODULE(adder){
  sc_in<int > a,b;
  sc_out<int > y;
  sc_event e;
  int add_sig1;
  SC_CTOR(adder){
    SC_METHOD(add);
	  sensitive << a << b;
	SC_METHOD(write1);
	  sensitive << e;
  }
  void add(){
    add_sig1=a.read()+b.read();	
	e.notify(2,SC_NS);
  }
  void write1(){
	  y.write(add_sig1);
  }
};