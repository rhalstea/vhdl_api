#include <expressions.h>

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
   _lhs(lhs), _rhs(rhs) {}

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

// ----- ----- ----- ----- ----- -----
// ----- ----- ----- ----- ----- -----

subtract::subtract(expression *lhs, expression *rhs) :
   _lhs(lhs), _rhs(rhs) {}

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
