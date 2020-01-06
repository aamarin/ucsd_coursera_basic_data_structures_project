CC = g++
INC_DIR = ../../catch
CXXFLAGS = -std=c++11 -O0 --coverage -Wall -I$(INC_DIR)
TEST_OBJS = process_packages.o process_packages_ut.o $(INC_DIR)/catch.o

test: $(TEST_OBJS)
	$(CC) $(CXXFLAGS) -o test $(TEST_OBJS)

catch.o: $(INC_DIR)/catch.hpp
process_packages.o : process_packages.hpp
process_packages_ut.o: $(INC_DIR)/catch.hpp
.PHONY: clean coverage

coverage:
	gcov process_packages_ut.C
	lcov --directory . -c -o process_packages.info
	genhtml -o . process_packages.info

clean:
	rm -rf $(TEST_OBJS) test ../../catch/*.gcda *.gcda ../../catch/*.gcno *.gcno *.gcov *.html *.png *.css *.info v1/ test_coverage/