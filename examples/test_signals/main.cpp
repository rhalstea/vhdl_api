#include <iostream>
#include <vector>
#include "vhdl/signals.h"

int main() {

   std::vector<vhdl::signal*> my_signals;

   my_signals.push_back( new vhdl::input_port("clk", 1) );
   my_signals.push_back( new vhdl::input_port("rst", 1) );
   my_signals.push_back( new vhdl::input_port("A", 8) );
   my_signals.push_back( new vhdl::input_port("B", 8) );
   my_signals.push_back( new vhdl::output_port("C", 8) );

   my_signals.push_back( new vhdl::signal("tmp_0", 0) );
   my_signals.push_back( new vhdl::signal("tmp_1", 1) );
   my_signals.push_back( new vhdl::signal("tmp_2", 8) );

   std::vector<vhdl::signal*>::iterator iter;
   for (iter = my_signals.begin(); iter != my_signals.end(); ++iter) {
      (*iter)->print(std::cout, " ;\n");
   }

   return 0;
}

