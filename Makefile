#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS := $(wildcard *.h*)
STUDENT_SOURCES := $(filter-out $(TEACHER_SOURCES), $(wildcard *.cpp))
STUDENT_OBJECTS := $(subst .cpp,.o,$(STUDENT_SOURCES))

run: test
	./$^

test: TestRunner.o Test.o $(STUDENT_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test
