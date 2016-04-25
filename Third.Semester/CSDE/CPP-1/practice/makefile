CC = g++
OBJS = main.o Array.o RangeArray.o
TARGET = run
CPPFLAGS = -g -Wall

all : $(TARGET)

$(TARGET) : $(OBJS) Array.h RangeArray.h
	$(CC) -o $(TARGET) $(OBJS)

clean :
	rm -rf $(TARGET) $(OBJS)
