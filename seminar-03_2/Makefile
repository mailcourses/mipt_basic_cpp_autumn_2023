CC=g++
CC_FLAGS=-std=c++20 -Wsign-compare -Wall -Wextra -Werror
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

all: test_bin

test_bin: searcher.o test.cpp
	$(CC) $(CC_FLAGS) searcher.o test.cpp -o test_bin $(CC_GTEST_FLAGS)

searcher.o: searcher.hpp searcher.cpp
	$(CC) $(CC_FLAGS) searcher.cpp -c

test:
	./test_bin

clean:
	rm -f *.o test_bin
