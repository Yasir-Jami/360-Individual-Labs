# Name: Yasir Jami (3077942)
# CMPT360 Lab 7

CC:=gcc
CFLAGS:= -Wall

pi: piLib.o test.o
	$(CC) $(CFLAGS) -o $@ $^ -lm -pthread

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o pi
