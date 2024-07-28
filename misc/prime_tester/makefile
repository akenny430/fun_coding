CC=clang++
INCLUDES=
CFLAGS=-g -Wall
LDFLAGS=-g
LDLIBS=

EXECUTABLE=prime

$(EXECUTABLE): main.o miller_rabin.o messages.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

main.o: main.cpp miller_rabin.hpp messages.hpp

miller_rabin.o: miller_rabin.cpp miller_rabin.hpp

messages.o: messages.cpp messages.hpp

.PHONY: clean
clean:
	rm -rf *.o $(EXECUTABLE)

.PHONY: all
all:
	clean $(EXECUTABLE)