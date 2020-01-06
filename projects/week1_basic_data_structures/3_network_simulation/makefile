CC = g++
INC_DIR = ../../catch
CXXFLAGS = -std=c++11 -Wall -I$(INC_DIR)
TEST_OBJS = process_packages.o process_packages_ut.o $(INC_DIR)/catch.o

test: $(TEST_OBJS)
	$(CC) $(CXXFLAGS) -o test $(TEST_OBJS)

catch.o: $(INC_DIR)/catch.hpp
process_packages.o : process_packages.hpp
process_packages_ut.o: $(INC_DIR)/catch.hpp
.PHONY: clean
clean:
	rm -rf $(TEST_OBJS) test