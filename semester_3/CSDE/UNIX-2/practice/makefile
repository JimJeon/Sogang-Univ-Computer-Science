CC = g++
OBJS = main.o Output.o String_Manipulation.o
SRCS = main.cpp Output.cpp String_Manipulation.cpp
CPPFLAGS = -g
TARGET = run

all: $(TARGET)

$(TARGET): $(OBJS) Header.h
	$(CC) -Wall -g -o $(TARGET) $(OBJS)

clean:
	rm -rf $(OBJS) $(TARGET)
