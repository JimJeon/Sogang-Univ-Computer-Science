CC = gcc
OBJS = main.o functions.o solver.o
TARGET = run
CFLAGS = -g -Wall

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -g -o $(TARGET) $(OBJS)

clean:
	rm -rf $(OBJS) $(TARGET)
