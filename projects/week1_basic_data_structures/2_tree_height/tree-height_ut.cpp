#include <vector>
#include "catch.hpp"
#include "tree-height.hpp"

std::vector<Node> init_vector(const std::vector<int>& input) {
    std::vector<Node> nodes(input.size());

    for(auto child_index = 0; child_index < input.size(); child_index++) {
        int parent_index = input[child_index];
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);

        nodes[child_index].key = child_index;
    }

    return nodes;
}

TEST_CASE("Testing findMaxHeight()", "[tree-height]") {
    set_kernel_stack_size();

    {
        const std::vector<int> TEST_VALUES = {4, -1, 4, 1, 1};
        auto nodes = init_vector(TEST_VALUES);
        REQUIRE(3 == findMaxHeight(nodes));
    }
}