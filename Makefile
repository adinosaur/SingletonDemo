
CXX=g++
CXXFLAGS=-g -O2 -m64 -fPIC --std=c++11 -fpermissive
#CXXFLAGS+=--save-temps 
LDFLAGS=-rdynamic

all: a.out libpatch.so

a.out: test_mgr.cpp main.cpp
	$(CXX) -c test_mgr.cpp -o test_mgr.o $(CXXFLAGS)
	$(CXX) -c main.cpp -o main.o $(CXXFLAGS)
	$(CXX) main.o test_mgr.o -o a.out $(LDFLAGS) -ldl

libpatch.so: patch.cpp
	$(CXX) -c patch.cpp -o patch.o $(CXXFLAGS)
	$(CXX) patch.o -o libpatch.so $(LDFLAGS) -shared

clean:
	rm -rf *.ii *.s *.o libpatch.so a.out
