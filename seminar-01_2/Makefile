CC=g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

all: test_bin main

test_bin: utils.o test.cpp
	$(CC) $(CC_FLAGS) utils.o test.cpp -o test_bin $(CC_GTEST_FLAGS)

main: utils.o main.cpp
	$(CC) $(CC_FLAGS) utils.o main.cpp -o main

utils.o: utils.hpp utils.cpp
	$(CC) $(CC_FLAGS) utils.cpp -c

test:
	./test_bin

clean:
	rm -f *.o main test_bin
