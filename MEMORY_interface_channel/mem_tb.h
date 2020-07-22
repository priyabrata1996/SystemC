#include<systemc.h>
#include"bus.h""
#define buswidth 32
#define memsize 3200
class mem_tb : public sc_core::sc_module{
public:
	sc_port<bus_if> mem_socket_tb{ "mem_socket_tb" };
	int write_trans, read_trans, bytes_read, bytes_write;
	sc_out<bool> reset{ "reset" };
	std::vector<uint32_t> buff1, buff2;
	sc_event e;
	uint32_t temp;
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
	for (uint32_t i=0; i < memsize; i++) {
		buff1.push_back(i+1);
		//cout << "buff1 DATA : " << buff1[i] << endl;
	}
	wait(10, SC_NS);
	int flag = 0;
	wait(SC_ZERO_TIME);
	for (int l = 0; l < 100; l++) {
		for (uint32_t i = 0; i < memsize; i++) {
			mem_socket_tb->buswrite1(i, buff1[i]);
			write_trans++;
			bytes_write += 4;
			wait(3, SC_NS);
		}
		wait(SC_ZERO_TIME);
		for (uint32_t k = 0; k < memsize; k++) {
			wait(SC_ZERO_TIME);
			mem_socket_tb->busread1(k, temp);
			buff2.push_back(temp);
			read_trans++;
			bytes_read += 4;
			wait(2, SC_NS);
			//cout << "BUFF2 DATA : " << temp<<endl;
		}
		for (uint32_t i = 0; i < memsize; i++) {
			//cout << "BUFF2 DATA : " << buff2[i] << " : BUFF1 DATA : " << buff1[i] << endl;
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