#include <iostream>
#include <vector>
#include <wire.h>

using namespace vhdl;

int main() {

  std::vector<wire *> my_wire;
  my_wire.push_back(new input_wire("clk", 1));
  my_wire.push_back(new input_wire("rst", 1));
  my_wire.push_back(new input_wire("input_ready", 1));
  my_wire.push_back(new output_wire("output_ready", 1));
  my_wire.push_back(new output_wire("done", 1));
  my_wire.push_back(new input_wire("stall", 1));
  my_wire.push_back(new wire("tmp00", 1));
  my_wire.push_back(new wire("tmp01", 8));


  my_wire.push_back(new output_wire("A0_address_channel0_out", 32));


  for (int i = 0; i < my_wire.size(); ++i)
    my_wire[i]->print(std::cout, " ;\n");

  std::cout << std::endl << std::endl;

  int sum = 0;
  for (int i = 0; i < my_wire.size(); ++i)
    sum += my_wire[i]->size();

  std::cout << "IOB's: " << sum << std::endl;
  return 0;
}
