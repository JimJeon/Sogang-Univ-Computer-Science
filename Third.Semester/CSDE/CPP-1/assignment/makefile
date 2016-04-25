CC = g++
OBJS = main.o str.o
TARGET = run
CPPFLAGS = -g -Wall

all : $(TARGET)

$(TARGET) : $(OBJS) str.h
	$(CC) -o $(TARGET) $(OBJS)

clean:
	rm -rf $(TARGET) $(OBJS)
