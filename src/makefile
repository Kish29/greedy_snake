CC := g++
CXX := g++

CFLAGS := -Wall -Wextra -I ../include --std=c++11 -m64
LDFLAGS := -pthread -lxcb

CPPS := greedy_snake.cpp

all: target 

.PHONY : all clean

target: $(CPPS) 
	$(CC) $(CFLAGS) $(CPPS) $(LDFLAGS) -o target

clean:
	rm -rf target
