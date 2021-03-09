CC = gcc
OBJS = main.o
SRCS = main.c
HEADERS = algorithms.h IO.h
TARGET = run
ifeq ($(BUILD),debug)
# "Debug" build - no optimization, and debugging symbols
CFLAGS = -O0 -g -Wall
else
# "Release" build - optimization, and no debug symbols
CFLAGS = -O2 -s -DNDEBUG
endif

all: $(TARGET)

debug:
	make "BUILD=debug"

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm run *.o
