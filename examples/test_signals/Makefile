LEVEL = ..
include $(LEVEL)/Makefile.config

EXE      = test_signals
LIBS     = -lvhdl


all: main.cpp
	$(CXX) $(CXX_FLAGS) -o $(EXE) $< $(LIBS)

clean:
	rm -rf $(EXE) *~ *.swp
