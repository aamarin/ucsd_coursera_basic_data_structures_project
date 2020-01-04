#include <string>
#include "catch.hpp"
#include "check_brackets.hpp"

TEST_CASE("Testing", "[brackets]") {
    REQUIRE(std::string("Success") == check_brackets("[]"));
    REQUIRE(std::string("Success") == check_brackets("()"));
    REQUIRE(std::string("Success") == check_brackets("{}"));

}