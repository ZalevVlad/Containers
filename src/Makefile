CC = gcc -std=c++17 -g -Wall -Werror -Wextra
OS = $(shell uname)
GCOV_FLAGS = --coverage

VECTOR = tests/s21_test_vector.cc
LIST = tests/s21_test_list.cc
ARRAY = tests/s21_test_array.cc
STACK = tests/s21_test_stack.cc
QUEUE = tests/s21_test_queue.cc
MAP = tests/s21_test_map.cc
MULTISET = tests/s21_test_multiset.cc
SET = tests/s21_test_set.cc
TEST = test.cc


ifeq ($(OS), Linux)
	CHECKFLAGS = -lgtest -lgtest_main -lrt -lm -lstdc++ -pthread
else
	CHECKFLAGS = -lgtest -lgtest_main -lm -lpthread  -lstdc++
endif

all: test clean

build_test: clean
	$(CC) $(TEST) -o test $(CHECKFLAGS)


test_vector: clean
	$(CC) $(VECTOR) -o test_vector $(CHECKFLAGS)
	./test_vector

test_set: clean
	$(CC) $(SET) -o test_set $(CHECKFLAGS)
	./test_set

test_multiset: clean
	$(CC) $(MULTISET) -o test_multiset $(CHECKFLAGS)
	./test_multiset

test_map: clean
	$(CC) $(MAP) -o test_map $(CHECKFLAGS)
	./test_map

test_list: clean
	$(CC) $(FLAGS) $(LIST) -o test_list $(CHECKFLAGS)
	./test_list

test_array: clean
	$(CC) $(ARRAY) -o test_array $(CHECKFLAGS)
	./test_array

test_stack: clean
	$(CC) $(STACK) -o test_stack $(CHECKFLAGS)
	./test_stack

test_queue: clean
	$(CC) $(QUEUE) -o test_queue $(CHECKFLAGS)
	./test_queue

test: build_test
	./test

gcov_report: test
	$(CC) $(GCOV_FLAGS) $(TEST) -o test $(CHECKFLAGS)
	./test
	lcov --directory . --capture --output-file gcov_test.info --exclude "test.cc" --exclude "/usr/include/*"
	genhtml -o report --show-details --highlight --legend gcov_test.info
	open report/index.html

style_check:
	clang-format -style=google -n ./tests/*.cc
	clang-format -style=google -n ./model/*.h

style_fix:
	clang-format -style=google -i ./tests/*.cc
	clang-format -style=google -i ./model/*.h

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test


docker_check:
	docker build -t "valgrind:1.0" .
	docker run --rm -v $(PWD):/tmp -w /tmp valgrind:1.0

clean:
	rm -rf report \
	report.info \
	*.gcda \
	*.gcno \
	test \
	test_* gcov_test.info