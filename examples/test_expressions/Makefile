LEVEL = ..
include $(LEVEL)/Makefile.config

EXE      = test_expressions
LIBS     = -lvhdl


all: main.cpp
	$(CXX) $(CXX_FLAGS) -o $(EXE) $< $(LIBS)

clean:
	rm -rf $(EXE) *~ *.swp
