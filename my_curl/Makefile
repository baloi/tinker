OBJS=urlget.o main.o
TARGET=urlget

# Linux:
CC = gcc
CFLAGS = -c -Wall -pedantic
CPPFLAGS = -DHAVE_STRCASECMP
LDFLAGS =

.c.o: urlget.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $*.c

$(TARGET): $(OBJS) Makefile
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f *.o *~ $(TARGET)

main.o: main.c urlget.h
