CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test
	rm -f llrec-test.o
	./llrec-test llrec-test2.in


#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) $^ -o $@

llrec-test.o: llrec-test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

llrec.o: llrec.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean


