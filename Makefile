CXX = g++
CXXFLAGS = -Wall

.PHONY: all clean demo test

all: demo test

clean:
	@rm -fv *.out

demo: demo.out

test: test.out
	./$^

demo.out: demo.cpp rational.h
	${CXX} ${CXXFLAGS} -o $@ $<

test.out: test.cpp rational.h unit_test.h
	${CXX} ${CXXFLAGS} -o $@ $<
