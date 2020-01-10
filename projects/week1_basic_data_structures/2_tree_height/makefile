CC = g++
INC_DIR = ../../catch
CXXFLAGS = -std=c++11 -O0 --coverage -Wall -I$(INC_DIR)
TEST_OBJS = tree-height.o tree-height_ut.o $(INC_DIR)/catch.o

test: $(TEST_OBJS)
	$(CC) $(CXXFLAGS) -o test $(TEST_OBJS)

catch.o: $(INC_DIR)/catch.hpp
tree-height.o : tree-height.hpp
tree-height_ut.o: $(INC_DIR)/catch.hpp
.PHONY: clean coverage

coverage:
	gcov tree-height_ut.C
	lcov --directory . -c -o tree-height.info
	genhtml -o . tree-height.info

clean:
	rm -rf $(TEST_OBJS) test ../../catch/*.gcda *.gcda ../../catch/*.gcno *.gcno *.gcov *.html *.png *.css *.info v1/ test_coverage/