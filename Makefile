#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS := $(wildcard *.h*)
TEACHER_SOURCES := Demo.cpp DemoGame.cpp TestCounter.cpp Test.cpp
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
