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

   // Test 3: subtract expression
   std::cout << std::endl
             << std::endl
             << "TEST 3: the subtract expression\n";
   vhdl::subtract *test_3 = new vhdl::subtract(new vhdl::expression(sig_0),
                                               new vhdl::expression(sig_1));
   test_3->print(std::cout);
   std::cout << std::endl;

   // Test 4: chain expressions
   std::cout << std::endl
             << std::endl
             << "TEST 4: chaining expressions together\n";
   vhdl::add *test_4a = new vhdl::add(new vhdl::expression(sig_0),
                                      test_2);
   vhdl::add *test_4b = new vhdl::add(test_3,
                                      new vhdl::expression(sig_0));
   vhdl::add *test_4c = new vhdl::add(test_4a, test_4b);

   test_4a->print(std::cout);
   std::cout << std::endl;
   test_4b->print(std::cout);
   std::cout << std::endl;
   test_4c->print(std::cout);
   std::cout << std::endl;

   return 0;
}
