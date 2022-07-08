CC = c++
CPP_FILES = $(wildcard *.cpp)
O_FILES = $(addsuffix .o,$(basename $(CPP_FILES)))

COMPILE: $(O_FILES)

%.o: %.cpp
	$(CC) $< -o $@

clear:
	rm *.o
	clear

strct11: strct11.o
	./$<

relops: relops.o
	./$<

mathops: mathops.o
	./$<

ioops: ioops.o
	./$<