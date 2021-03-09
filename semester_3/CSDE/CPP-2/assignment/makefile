CC = g++
OBJS = main.o Array.o GrowableArray.o
TARGET = run
CPPFLAGS = -g -Wall

all: $(TARGET)

$(TARGET) : $(OBJS) Array.h GrowableArray.h
	$(CC) -o $(TARGET) $(OBJS)

clean:
	rm -rf $(TARGET) $(OBJS)
