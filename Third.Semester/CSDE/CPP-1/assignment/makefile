CC = g++
OBJS = main.o str.o
TARGET = run
CPPFLAGS = -Wall

all : $(TARGET)

$(TARGET) : $(OBJS) str.h
	$(CC) -o $(TARGET) $(OBJS)

clean:
	rm -rf $(TARGET) $(OBJS)
