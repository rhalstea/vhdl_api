#include <iostream>
#include "vhdl/signals.h"

int main() {
   vhdl::signal *s1 = new vhdl::signal("clk", 0);
   vhdl::signal *s2 = new vhdl::signal("clk", 1);
   vhdl::signal *s3 = new vhdl::signal("clk", 2);

   s1->print(std::cout, ";\n");
   s2->print(std::cout, ";\n");
   s3->print(std::cout, ";\n");

   return 0;
}

