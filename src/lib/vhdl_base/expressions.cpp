#include <expressions.h>
#include <vhdl_messages.h>

using namespace vhdl;

// ----- ----- ----- ----- ----- -----
// ----- ----- ----- ----- ----- -----
expression::expression() {
   _signal = NULL;
}

expression::expression(signal *sig) :
   _signal(sig) {}

expression::~expression() {
   // nothing to do yet
}

void expression::print(std::ostream &stream) {
   stream << _signal->name();
}

unsigned expression::num_bits() {
   return _signal->size();
}

// ----- ----- ----- ----- ----- -----
// ----- ----- ----- ----- ----- -----

add::add(expression *lhs, expression *rhs) :
   _lhs(lhs), _rhs(rhs) 
{
   if (lhs->num_bits() != rhs->num_bits())
      WARNING("Creating an add expression with different sized signals"); 
}

add::~add() {
   // nothing to do yet
}

void add::print(std::ostream &stream) {
   stream << "(";
   _lhs->print(stream);
   stream << " + ";
   _rhs->print(stream);
   stream << ")";
}

unsigned add::num_bits() {
   return _lhs->num_bits();
}
// ----- ----- ----- ----- ----- -----
// ----- ----- ----- ----- ----- -----

subtract::subtract(expression *lhs, expression *rhs) :
   _lhs(lhs), _rhs(rhs) 
{
   if (lhs->num_bits() != rhs->num_bits())
      WARNING("Creating a subtract expression with different "
              << "sized signals");
}

subtract::~subtract() {
   // nothing to do yet
}

void subtract::print(std::ostream &stream) {
   stream << "(";
   _lhs->print(stream);
   stream << " - ";
   _rhs->print(stream);
   stream << ")";
}

unsigned subtract::num_bits() {
   return _lhs->num_bits();
}
