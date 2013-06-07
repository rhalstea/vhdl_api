#include <iostream>
#include <vhdl/component.h>

int main() {

   vhdl::component comp("test");

   comp.add_port(new vhdl::input_port("clk", 1));
   comp.add_port(new vhdl::input_port("rst", 1));
   comp.add_port(new vhdl::input_port("A", 8));
   comp.add_port(new vhdl::input_port("B", 8));
   comp.add_port(new vhdl::output_port("C", 8));
   
   comp.print_entity(std::cout);

   return 0;
}

