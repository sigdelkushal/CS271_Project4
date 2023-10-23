# target: dependencies
# 	action

all: test

test: bst.cpp 
	g++ bst -o test

clean:
	rm test