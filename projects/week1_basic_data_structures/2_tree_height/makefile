CC = g++
INC_DIR = ../../catch
CXXFLAGS = -std=c++11 -Wall -I$(INC_DIR)
TEST_OBJS = tree-height.o tree-height_ut.o $(INC_DIR)/catch.o

test: $(TEST_OBJS)
	$(CC) $(CXXFLAGS) -o test $(TEST_OBJS)

catch.o: $(INC_DIR)/catch.hpp
tree-height.o : tree-height.hpp
tree-height-ut.o: $(INC_DIR)/catch.hpp tree-height.hpp
.PHONY: clean
clean:
	rm $(TEST_OBJS) test