#ifndef bus_h
#define bus_h

class bus_if : virtual public sc_interface {
public:
	virtual void buswrite1(uint32_t addr, uint32_t data) = 0;
	virtual void busread1(uint32_t addr, uint32_t& data) = 0;
};
class bus_channel : public bus_if, public sc_prim_channel {
public:
	sc_out<uint32_t > addr_line_tb{"addr_line_tb"};
	sc_out<uint32_t >data_in_tb{ "data_in_tb" };
	sc_in<uint32_t >data_out_tb{ "data_out_tb" };
	sc_out_resolved rw_p{ "rw_p" };
	bus_channel(sc_module_name nm) :sc_prim_channel(nm) {}
	virtual void buswrite1(uint32_t addr, uint32_t data);
	virtual void busread1(uint32_t addr, uint32_t& data);
};
void bus_channel::buswrite1(uint32_t addr, uint32_t data) {
	wait(SC_ZERO_TIME);
	addr_line_tb->write(addr);
	data_in_tb->write(data);
	rw_p->write(SC_LOGIC_0); // Write pulse
	wait(SC_ZERO_TIME);
	rw_p->write(SC_LOGIC_Z);
}
void bus_channel::busread1(uint32_t addr, uint32_t &data) {
	wait(SC_ZERO_TIME);
	addr_line_tb->write(addr);
	rw_p->write(SC_LOGIC_1); // Write pulse
	wait(data_out_tb.value_changed_event());
	data = data_out_tb->read();
	wait(SC_ZERO_TIME);
	rw_p->write(SC_LOGIC_Z);
}

#endif; // !bus.h