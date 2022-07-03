CC = c++
CPP_FILES = $(wildcard *.cpp)
O_FILES = $(addsuffix .o,$(basename $(CPP_FILES)))

COMPILE: $(O_FILES)

strct11: strct11.o
	./$<

relops: relops.o
	./$<

%.o: %.cpp
	$(CC) $< -o $@

clear:
	rm *.o
	clear