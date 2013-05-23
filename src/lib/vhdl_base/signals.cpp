#include <signals.h>

using namespace vhdl;

// ----- ----- ----- ----- ----- -----
// ----- ----- ----- ----- ----- -----

signal::signal(std::string name, unsigned bit_width) : 
   _name(name), _size(bit_width) { }

signal::~signal() {
   // nothing to do yet
}

void signal::print(std::ostream &stream, std::string append) {
   stream << "signal " << _name << ": std_logic";

   if (_size == 0) // special case
      stream << "_vector(0 downto 0)";
   else if (_size > 1)
      stream << "_vector(" << _size-1 << " downto 0)";

   stream << append;
}

std::string signal::name() { return _name; }
unsigned    signal::size() { return _size; }

void signal::set_name(std::string name) {
   _name = name;
}

void signal::set_size(unsigned size) {
   _size = size;
}

// ----- ----- ----- ----- ----- -----
// ----- ----- ----- ----- ----- -----

input_port::input_port(std::string name, unsigned bit_width) :
   signal(name, bit_width) {}

input_port::~input_port() {
   // nothing to do yet
}

void input_port::print(std::ostream &stream, std::string append) {
   stream << _name << ": in std_logic";

   if (_size == 0) // special case
      stream << "_vector(0 downto 0)";
   else if (_size > 1)
      stream << "_vector(" << _size-1 << " downto 0)";

   stream << append;
}

// ----- ----- ----- ----- ----- -----
// ----- ----- ----- ----- ----- -----

output_port::output_port(std::string name, unsigned bit_width) :
   signal(name, bit_width) {}

output_port::~output_port() {
   // nothing to do yet
}

void output_port::print(std::ostream &stream, std::string append) {
   stream << _name << ": out std_logic";

   if (_size == 0) // special case
      stream << "_vector(0 downto 0)";
   else if (_size > 1)
      stream << "_vector(" << _size-1 << " downto 0)";

   stream << append;
}
