CC = c++
CPP_FILES = $(wildcard *.cpp)
O_FILES = $(addsuffix .o,$(basename $(CPP_FILES)))

COMPILE: $(O_FILES)

%.o: %.cpp
	$(CC) $< -o $@

clear:
	rm *.o
	clear

#Experiments
timer: timer.o
	./$<

#Chapter 04
strct11: strct11.o
	./$<
relops: relops.o
	./$<
mathops: mathops.o
	./$<
ioops: ioops.o
	./$<

#Chapter 05
castfunc: castfunc.o
	./$<
castops: castops.o
	./$<
castcons: castcons.o
	./$<
castcopy: castcopy.o
	./$<
cls2cls: cls2cls.o
	./$<