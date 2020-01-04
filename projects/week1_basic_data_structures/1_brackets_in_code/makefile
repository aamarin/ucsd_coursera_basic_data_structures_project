CC = g++
INC_DIR = ../../catch
CXXFLAGS = -std=c++11 -Wall -I$(INC_DIR)
TEST_OBJS = check_brackets_ut.o check_brackets.o $(INC_DIR)/catch.o

test: $(TEST_OBJS)
	$(CC) $(CXXFLAGS) -o test $(TEST_OBJS)

catch.o: $(INC_DIR)/catch.hpp
check_brackets.o : $(INC_DIR)/catch.hpp
check_brackets_ut.o: $(INC_DIR)/catch.hpp
.PHONY: clean
clean:
	rm $(TEST_OBJS) test