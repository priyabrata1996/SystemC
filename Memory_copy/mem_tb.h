#include<systemc.h>
#define buswidth 32
#define memsize 3200
SC_MODULE(mem_tb){
	sc_out<sc_bv<buswidth> > addr_line;
	sc_out<sc_bv<buswidth> >data_in;
	sc_in<sc_bv<buswidth> >data_out;
	sc_out<bool > read_en, write_en;
	sc_out<bool> reset;
	int write_trans, read_trans, bytes_read, bytes_write;
	std::vector<int> buff1, buff2;
	sc_event e;
	SC_CTOR(mem_tb){
		write_trans = 0;
		read_trans = 0;
		bytes_read = 0;
		bytes_write = 0;
		SC_THREAD(test);
	}
	void test();
};
void mem_tb::test() {
	for (int i=0; i < memsize; i++) {
		buff1.push_back(i+1);
		//cout << "buff1 DATA : " << buff1[i] << endl;
	}
	wait(10, SC_NS);
	int flag = 0;
	wait(SC_ZERO_TIME);
	for (int l = 0; l < 100; l++) {
		for (int i = 0; i < memsize; i++) {
			wait(SC_ZERO_TIME);
			sc_bv<buswidth> temp1 = (sc_bv<buswidth>)i;
			sc_bv<buswidth> temp2 = (sc_bv<buswidth>)buff1[i];
			addr_line.write(temp1);
			data_in.write(temp2);
			wait(SC_ZERO_TIME);
			write_en.write(true);
			wait(SC_ZERO_TIME);
			write_trans++;
			bytes_write += 4;
			write_en.write(false);
			wait(3, SC_NS);
		}
		wait(SC_ZERO_TIME);
		for (int k = 0; k < memsize; k++) {
			addr_line.write((sc_bv<buswidth>)k);
			read_en.write(true);
			wait(data_out.value_changed_event());
			sc_bv<buswidth> temp = data_out.read();
			buff2.push_back(temp.to_uint());
			read_trans++;
			bytes_read += 4;
			wait(SC_ZERO_TIME);
			read_en.write(false);
			wait(2, SC_NS);
			//cout << "BUFF2 DATA : " << buff2[k] << " : BUFF1 DATA : " << buff1[k] << endl;
		}
		for (int i = 0; i < memsize; i++) {
			if (buff1[i] != buff2[i]) {
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		buff2.clear();
		wait(SC_ZERO_TIME);
		reset.write(true);
		wait(SC_ZERO_TIME);
		reset.write(false);
	}
	if (flag == 1)
		std::cout << "read write success" << endl;
	else
		std::cout << "Not matched" << endl;
	cout << "Number of WRITE Transactions = " << write_trans << endl;
	cout << "Number of READ Transactions = " << read_trans << endl;
	cout << "Total Number of bytes written = " << bytes_write << endl;
	cout << "Total Number of bytes read = " << bytes_read << endl;
	cout << "Simulation Time" << sc_time_stamp() << endl;
}