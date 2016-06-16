CC = g++ -std=c++11

DEBUG = g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall -g

GOOGLE_TEST_LIB =  -lgtest -lgtest_main -lpthread

TEST_CASES = Vector2Test.cpp
 
default: gtest_tutorial

gtest_tutorial: ALL_TEST_CASES.cpp $(OBJECTS)
	$(CC) $(LFLAGS) ALL_TEST_CASES.cpp $(TEST_CASES) $(GOOGLE_TEST_LIB) -o vector_tests.out

clean:
	rm *.o
