CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes
OBJS=llrec.o llrec-test.o
all: llrec-test

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
	
stack-test: stack-test.o
	$(CXX) $(CXXFLAGS) -o $@ stack-test.o

clean:
	rm -f *.o rh llrec-test stack-test *~

.PHONY: clean 