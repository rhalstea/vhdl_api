#ifndef __VHDL_COMPONENT_H__
#define __VHDL_COMPONENT_H__

#include <iostream>
#include <string>
#include <set>

#include "signals.h"
#include "statements.h"

namespace vhdl {
   class component {
      private:
         void print_libraries(std::ostream &stream);
         void print_port_list(std::ostream &stream);
         void print_architecture(std::ostream &stream);
         void print_signals(std::ostream &stream);
         void print_statements(std::ostream &stream);

      protected:
         std::string _name;
         std::string _architecture_name;
         std::set<vhdl::signal*> _signals;
         std::set<vhdl::statement*> _statements;

      public:
         component(std::string name);
         ~component();
         void add_port(vhdl::signal *s);
         void add_statement(vhdl::statement *s);
         //void add_library();

         virtual void print_entity(std::ostream &stream);
   };
}

#endif

