CC = c++
CPP_FILES = $(wildcard *.cpp)
O_FILES = $(addsuffix .o,$(basename $(CPP_FILES)))

COMPILE: $(O_FILES)

%.o: %.cpp
	$(CC) $< -o $@

clear:
	rm *.o
	clear

embed: embed.o 
	./$<
base_a: base_a.o
	./$<
tstbasea: tstbasea.o
	./$<
puba: puba.o
	./$<
pubinht: pubinht.o
	./$<
priva: priva.o
	./$<
privinht: privinht.o
	./$<
polyinh1: polyinh1.o
	./$<
