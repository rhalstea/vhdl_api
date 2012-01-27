GCC = g++
GCC_FLAGS = -fPIC
OBJECTS = wire.o connection.o #ports.o module.o

all: $(OBJECTS)
	@mkdir -p ../lib
	ld -G *.o -o ../lib/libvhdl.so

%.o: %.cpp %.h
	$(GCC) $(GCC_FLAGS) -c $<

clean:
	rm -rf *.o ../lib/*.so *.~