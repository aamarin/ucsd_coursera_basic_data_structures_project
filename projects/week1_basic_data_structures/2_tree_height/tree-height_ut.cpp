#include "catch.hpp"
#include "tree-height.hpp"

TEST_CASE("Testing findMaxHeight()", "[tree-height]") {
    set_kernel_stack_size();
    std::vector<Node> nodes;

    REQUIRE(3 == findMaxHeight(nodes, nodes.size()));
}