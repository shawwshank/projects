CXX=g++
CPPFLAGS =-std=c++11 -Wall -g

all: HW11		
HW11: asd.cpp User.hpp UserList.hpp Wall.hpp WallPost.hpp WallpostComment.hpp Hashtable.hpp
	${CXX} asd.cpp -o $@ ${CPPFLAGS}

.PHONY: clean

clean:
	-@rm HW11 2>/dev/null || true
