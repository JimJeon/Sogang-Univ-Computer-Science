CC = gcc
OBJS = main.o io.o my_quick_sorts.o
FLAGS = -Wall
TARGET = run
ifeq ($(BUILD),debug)
CFLAGS = -O0 -g -Wall
else
CFLAGS = -O2 -s -DNDEBUG
endif

all: $(TARGET)

debug:
	make "BUILD=debug"

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm $(OBJS) $(TARGET)
