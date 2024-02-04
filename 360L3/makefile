# Name: Yasir Jami (3077942)
# 360 Lab 3

CC:=gcc
CFLAGS:= -Wall
# Do not need c11 since there may be problems, defaults to current highest standard (c20)

fileType: test.o #fileType.o #fileTypeTest.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o fileType
