#include <iostream>
#include <vector>
#include <cassert>

#include <wire.h>
#include <connection.h>

int main() {

  vhdl::input_wire  *clk = new vhdl::input_wire("clk", 1);
  vhdl::output_wire *A   = new vhdl::output_wire("A", 32);

  vhdl::input_wire  *clk_tmp1 = new vhdl::input_wire("clk_tmp1", 1);
  vhdl::input_wire  *clk_tmp2 = new vhdl::input_wire("clk_tmp2", 1);
  vhdl::output_wire *A_tmp1   = new vhdl::output_wire("A_tmp1", 32);
  

  vhdl::connection *con_1 = new vhdl::connection("tmp0", clk, clk_tmp1);
  vhdl::connection *con_2 = new vhdl::connection("tmp1", A, A_tmp1);

  std::cout << "print declarations for tmp0 and tmp1:" << std::endl;
  con_1->print_declaration(std::cout, ";\n");
  con_2->print_declaration(std::cout, ";\n");
  std::cout << std::endl;

  std::cout << "print name: ";
  con_1->print_name(std::cout, ", ");
  con_2->print_name(std::cout, "\n");
  std::cout << std::endl;


  std::cout << "verify has_destination function:" << std::endl;
  assert(con_1->has_destination(clk_tmp1));
  assert(con_2->has_destination(A_tmp1));
  assert(!con_1->has_destination(clk_tmp2));
  assert(!con_2->has_destination(clk_tmp1));
  assert(!con_2->has_destination(clk_tmp2));
  std::cout << "PASSED" << std::endl << std::endl;


  std::cout << "verify add_destination:" << std::endl;
  con_1->add_destination(clk_tmp2);
  assert(con_1->has_destination(clk_tmp1));
  assert(con_1->has_destination(clk_tmp2));
  std::cout << "PASSED" << std::endl << std::endl;


  std::cout << "verify source function:" << std::endl;
  con_1->source()->print(std::cout, ";\n");
  con_2->source()->print(std::cout, ";\n");
  std::cout << std::endl;


  std::cout << "verify size function:" << std::endl;
  assert(con_1->size() == 2);
  assert(con_2->size() == 1);
  std::cout << "PASSED" << std::endl << std::endl;


  std::cout << "verify destination function:" << std::endl;
  assert(con_1->destination(0) == clk_tmp1);
  assert(con_1->destination(1) == clk_tmp2);
  assert(con_2->destination(0) == A_tmp1);
  std::cout << "PASSED" << std::endl << std::endl;

  return 0;
}
