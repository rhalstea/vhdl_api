#include "statements.h"

using namespace vhdl;

// ----- ----- ----- ----- ----- -----
// ----- ----- ----- ----- ----- -----
statement::statement() :
   _destination(NULL), _source(NULL) {}

statement::statement(signal *dest, expression *src) :
   _destination(dest), _source(src) {}

statement::~statement() {
   // nothing to do yet
}

// ----- ----- ----- ----- ----- -----
// ----- ----- ----- ----- ----- -----
assignmentStatement::assignmentStatement(signal *dest, expression *src) :
   statement(dest, src) {}

assignmentStatement::~assignmentStatement() {
   // nothing to do yet
}

void assignmentStatement::print(std::ostream &stream) {
   //_destination->print(stream);
   stream << _destination->name();
   stream << " <= ";
   _source->print(stream);
   stream << ";";
}
