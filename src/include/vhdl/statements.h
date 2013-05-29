#ifndef __VHDL_STATEMENTS_H__
#define __VHDL_STATEMENTS_H__

#include <string>
#include <ostream>

#include "signals.h"
#include "expressions.h"

namespace vhdl {
   class statement {
      protected:
         statement();
         statement(vhdl::signal *dest, vhdl::expression *src);
         vhdl::signal      *_destination;
         vhdl::expression  *_source;

      public:
         virtual ~statement();
         virtual void print(std::ostream &stream) = 0;
   };

   class assignmentStatement : public statement {
      private:

      protected:

      public:
         assignmentStatement(vhdl::signal *dest, vhdl::expression *src);
         ~assignmentStatement();
         virtual void print(std::ostream &stream);
   };
}

#endif

