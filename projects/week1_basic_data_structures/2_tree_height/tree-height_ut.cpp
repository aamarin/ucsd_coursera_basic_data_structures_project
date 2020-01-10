#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "catch.hpp"
#include "tree-height.hpp"

int createExpectedOutput(const std::string& fileName) {
    std::ifstream infile(fileName);

    int output = 0;
    infile >> output;

    return output;
}

std::vector<Node> buildTreeFromInput(const std::string& fileName) {
    std::ifstream infile(fileName);

    int size = 0;
    infile >> size;

    std::vector<Node> nodes(size);

  for (int child_index = 0; child_index < size; child_index++) {
    int parent_index;
    infile >> parent_index;

    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);

    nodes[child_index].key = child_index;
  }

    return nodes;
}

bool passedCheck(const std::string& fileName, const int expected) {

    std::vector<Node> inputTree = buildTreeFromInput(fileName);
    const int height = findMaxHeight(inputTree);

    REQUIRE(height == expected);
    return (height == expected);
}

TEST_CASE("Testing findMaxHeight()", "[tree-height]") {
    set_kernel_stack_size();
    std::vector<std::string> test_cases;

     for(auto i = 1; i < 25; ++i) {
         test_cases.push_back(std::to_string(i));
    }

    for(auto test : test_cases) {
        std::string pre = "";
        if(std::stoi(test) < 10) {
            pre = "0";
        }

        const std::string solutionFileName = "tests/" + pre + test + ".a";
        const std::string inputFileName = "tests/" + pre + test;
        // std::cout << solutionFileName << " " << inputFileName << std::endl;

        const int EXPECTED = createExpectedOutput(solutionFileName);
        REQUIRE( passedCheck(inputFileName, EXPECTED) );
    }
}