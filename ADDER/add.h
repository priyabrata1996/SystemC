#include<systemc.h>
SC_MODULE(adder){
  sc_in<int > a,b;
  sc_out<int > y;
  sc_signal<int >add_sig1;
  SC_CTOR(adder){
    SC_METHOD(add){
	  sensitive << a << b;
	  dont_initialize();
	}		
	SC_METHOD(write1){
	  sensitive << add_sig1;
	  dont_initialize();
	}
  }
  void add();
  void write1();
};
  void adder :: add(){
	  add_sig1=a.read()+b.read();
  }
  void adder :: write1(){
	  y.write(add_sig1);
  }