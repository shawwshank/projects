CXX=g++
CPPFLAGS =-std=c++11 -Wall -g

all: HW10		
HW10: main.cpp Student.cpp HashTable.hpp 
	${CXX} main.cpp Student.cpp -o $@ ${CPPFLAGS}

.PHONY: clean

clean:
	-@rm HW10 2>/dev/null || true
