CC = gcc
CFLAGS = -Wall -std=c99 -g
LIBS = -lm

OBJS = main.o artemis.o validaciones.o
TARGET = simulador_artemis

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

main.o: main.c artemis.h validaciones.h
	$(CC) $(CFLAGS) -c main.c

artemis.o: artemis.c artemis.h
	$(CC) $(CFLAGS) -c artemis.c

validaciones.o: validaciones.c validaciones.h
	$(CC) $(CFLAGS) -c validaciones.c

clean:
	rm -f $(OBJS) $(TARGET)