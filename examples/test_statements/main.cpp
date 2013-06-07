#include <iostream>

#include <signals.h>
#include <expressions.h>
#include <statements.h>

int main() {
   vhdl::signal *sig_1 = new vhdl::input_port("A", 8);
   vhdl::signal *sig_2 = new vhdl::output_port("B", 8);

   vhdl::expression *exp_0 = new vhdl::expression(sig_1);
   vhdl::assignmentStatement *stmt_0 = 
      new vhdl::assignmentStatement(sig_2, exp_0);
   stmt_0->print(std::cout);

   return 0;
}

