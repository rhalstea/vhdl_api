#include <iostream>
#include <signals.h>
#include <expressions.h>


int main() {
   vhdl::signal *sig_0 = new vhdl::signal("sig_0", 8); 
   vhdl::signal *sig_1 = new vhdl::signal("sig_1", 8); 

   // Test 1: assignment expression
   std::cout << "TEST 1: assign a signal to an expression\n";
   vhdl::expression *test_1 = new vhdl::expression(sig_0);
   test_1->print(std::cout);
   std::cout << std::endl;

   // Test 2: add expression
   std::cout << std::endl
             << std::endl
             << "TEST 2: the add expression\n";
   vhdl::add *test_2 = new vhdl::add(new vhdl::expression(sig_0),
                                     new vhdl::expression(sig_1));
   test_2->print(std::cout);
   std::cout << std::endl;

   // Test 3: chain expressions
   std::cout << std::endl
             << std::endl
             << "TEST 3: chaining expressions together\n";
   vhdl::add *test_3a = new vhdl::add(new vhdl::expression(sig_0),
                                      test_2);
   vhdl::add *test_3b = new vhdl::add(test_2,
                                      new vhdl::expression(sig_0));
   vhdl::add *test_3c = new vhdl::add(test_3a, test_3b);

   test_3a->print(std::cout);
   std::cout << std::endl;
   test_3b->print(std::cout);
   std::cout << std::endl;
   test_3c->print(std::cout);
   std::cout << std::endl;

   return 0;
}
