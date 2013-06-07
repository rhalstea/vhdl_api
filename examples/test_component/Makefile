LEVEL = ..
include $(LEVEL)/Makefile.config

EXE      = test_component
LIBS     = -lvhdl


all: main.cpp
	$(CXX) $(CXX_FLAGS) -o $(EXE) $< $(LIBS)

clean:
	rm -rf $(EXE) *~ *.swp
