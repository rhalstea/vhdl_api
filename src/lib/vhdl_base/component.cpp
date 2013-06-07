#include "component.h"

using namespace vhdl;

component::component(std::string name) {
   _name = name;
   _architecture_name = "behav";
   _signals.clear();
   _statements.clear();
}

component::~component() {
   // nothing to do yet
}

void component::add_port(vhdl::signal *s) {
   _signals.insert(s);
}

void component::add_statement(vhdl::statement *s) {
   _statements.insert(s);
}

void component::print_entity(std::ostream &stream) {
   print_libraries(stream);

   stream << "entity " << _name << " is" << std::endl
          << "port(" << std::endl;

   print_port_list(stream);
   stream << ");" << std::endl
          << "end " << _name << std::endl << std::endl;

   print_architecture(stream);

}

void component::print_libraries(std::ostream &stream) {
   stream << "library ieee;" << std::endl
          << "use ieee.std_logic_1164.all;" << std::endl
          << "use ieee.std_logic_arith.all;" << std::endl
          << "use ieee.std_logic_unsigned.all;" << std::endl;
}

void component::print_port_list(std::ostream &stream) {

   bool first = true;
   std::set<vhdl::signal*>::iterator sig;

   for (sig = _signals.begin(); sig != _signals.end(); ++sig) {
      if (dynamic_cast<vhdl::input_port*>(*sig) ||
          dynamic_cast<vhdl::output_port*>(*sig)) 
      {
         if (first) {
            (*sig)->print(stream);
            first = false;
         }
         else {
            stream << ";" << std::endl;
            (*sig)->print(stream);
         }
      }
   }
   stream << std::endl;
}

void component::print_architecture(std::ostream &stream) {
   stream << "architecture " << _architecture_name << " of " << _name << " is" << std::endl;
   print_signals(stream);
   stream << std::endl
          << "begin" << std::endl;
   print_statements(stream);
   stream << std::endl
          << "end " << _architecture_name << std::endl;
}

void component::print_signals(std::ostream &stream) {
}

void component::print_statements(std::ostream &stream) {
}

