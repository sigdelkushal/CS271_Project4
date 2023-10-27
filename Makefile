# -*- Makefile -*-

# target: dependencies
# 	action

all: test usecase

test: test_bst.cpp bst.cpp bst.h
	g++ test_bst.cpp -o test
usecase: main.cpp bst.cpp bst.h
	g++ main.cpp -o usecase

clean:
	rm test