#include <iostream>
#include <vector>
#include <connection.h>

using namespace vhdl;

int main() {

  connection_list my_connections;

  input_wire *clk = new input_wire("clk", 1);
  input_wire *rst = new input_wire("rst", 1);

  wire *tmp_0 = new wire("clk_tmp_0", 1);
  wire *tmp_1 = new wire("clk_tmp_1", 1);
  wire *tmp_2 = new wire("rst_tmp_0", 1);

  wire *src_0 = new wire("src_wire", 32);
  wire *dest_0 = new wire("dest_wire_0", 32);
  wire *dest_1 = new wire("dest_wire_1", 32);

  my_connections.add_io_connection(clk, tmp_0);
  my_connections.add_io_connection(clk, tmp_1);
  my_connections.add_io_connection(rst, tmp_2);

  my_connections.add_connection(src_0, dest_0);
  my_connections.add_connection(src_0, dest_1);

  std::cout << "signal for " << clk->name() << " is " 
	    << my_connections.get_connection_name(clk) << std::endl;
  std::cout << "signal for " << rst->name() << " is " 
	    << my_connections.get_connection_name(rst) << std::endl;
  std::cout << "signal for " << src_0->name() << " is " 
	    << my_connections.get_connection_name(src_0) << std::endl;

  std::cout << "signal for " << tmp_0->name() << " is " 
	    << my_connections.get_connection_name(tmp_0) << std::endl;
  std::cout << "signal for " << tmp_1->name() << " is " 
	    << my_connections.get_connection_name(tmp_1) << std::endl;
  std::cout << "signal for " << tmp_2->name() << " is " 
	    << my_connections.get_connection_name(tmp_2) << std::endl;

  std::cout << "signal for " << dest_0->name() << " is " 
	    << my_connections.get_connection_name(dest_0) << std::endl;
  std::cout << "signal for " << dest_1->name() << " is " 
	    << my_connections.get_connection_name(dest_1) << std::endl;

  return 0;
}
