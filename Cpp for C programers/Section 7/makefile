CC = c++
CPP_FILES = $(wildcard *.cpp)
O_FILES = $(addsuffix .o,$(basename $(CPP_FILES)))

COMPILE: $(O_FILES)

%.o: %.cpp
	$(CC) $< -o $@

clear:
	rm *.o
	clear

p2bp2d: p2bp2d.o 
	./$<
