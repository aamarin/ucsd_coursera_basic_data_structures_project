CC = g++
INC_DIR = ../../catch
CXXFLAGS = -std=c++11 -O0 --coverage -Wall -I$(INC_DIR)
TEST_OBJS = stack_with_max_naive.o stack_with_max_naive_ut.o $(INC_DIR)/catch.o

test: $(TEST_OBJS)
	$(CC) $(CXXFLAGS) -o test $(TEST_OBJS)

catch.o: $(INC_DIR)/catch.hpp
stack_with_max_naive.o : stack_with_max_naive.hpp
stack_with_max_naive_ut.o: $(INC_DIR)/catch.hpp
.PHONY: clean coverage

coverage:
	gcov stack_with_max_naive_ut.C
	lcov --directory . -c -o stack_with_max_naive.info
	genhtml -o . stack_with_max_naive.info

clean:
	rm -rf $(TEST_OBJS) test ../../catch/*.gcda *.gcda ../../catch/*.gcno *.gcno *.gcov *.html *.png *.css *.info v1/ test_coverage/