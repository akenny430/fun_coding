CXX=clang++
CXXFLAGS=-g -Wall -std=c++2a

EXECUTABLE=prime

$(EXECUTABLE): main.o miller_rabin.o messages.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp miller_rabin.hpp messages.hpp

miller_rabin.o: miller_rabin.cpp miller_rabin.hpp

messages.o: messages.cpp messages.hpp

.PHONY: clean
clean:
	rm -rf *.o $(EXECUTABLE)

.PHONY: all
all:
	clean $(EXECUTABLE)