#include<iostream>
#include<systemc.h>
#include<add.h>
#include<test.h>
using namespace std;

SC_MODULE(sys){
  adder *a1;
  testbench1 *t1;
  sc_signal<int > my_sig1,my_sig2,my_sig3;
  SC_CTOR(sys){
    t1= new testbench1("t1");
    t1-> a(my_sig1);
    t1-> b(my_sig2);
    t1-> y(my_sig3);
    
    
    a1= new adder("a1");
    a1->a(my_sig1);
    a1->b(my_sig2);
    a1->y(my_sig3);
  }
  ~sys(){
    delete a1;
    delete t1;
  }
};

sys *s=NULL;
int sc_main(int argc, char* argv[]){
  s= new sys("s");
  sc_start();
  return 0;
}