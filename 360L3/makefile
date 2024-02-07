# Name: Yasir Jami (3077942)
# CMPT360 Lab 3

CC:=gcc
CFLAGS:= -Wall
# Do not need c11 since there may be problems, defaults to current highest standard (c20)

fileType: fileType.o fileTypeLib.o 
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o fileType
