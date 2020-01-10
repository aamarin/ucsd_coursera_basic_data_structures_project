#include "catch.hpp"
#include "stack_with_max_naive.hpp"

TEST_CASE("Testing StackWithMax", "[stack_max]") {

    SECTION("1st"){
        StackWithMax stack;

        stack.Push(1);
        stack.Push(2);

        REQUIRE(stack.Max() == 2);

        stack.Pop();

        REQUIRE(stack.Max() == 1);
    }

    SECTION("2nd"){
        StackWithMax stack;

        stack.Push(7);
        stack.Push(1);
        stack.Push(7);

        REQUIRE(stack.Max() == 7);

        stack.Pop();

        REQUIRE(stack.Max() == 7);
    }

    SECTION("3rd"){
        StackWithMax stack;

        stack.Push(2);
        stack.Push(3);
        stack.Push(9);
        stack.Push(7);
        stack.Push(2);

        REQUIRE(stack.Max() == 9);

        stack.Pop();

        REQUIRE(stack.Max() == 9);
    }

    {
        StackWithMax stack;

        stack.Push(0);
        REQUIRE(stack.Max() == 0);

        stack.Push(1);
        REQUIRE(stack.Max() == 1);

        stack.Push(2);
        REQUIRE(stack.Max() == 2);

        stack.Push(3);
        REQUIRE(stack.Max() == 3);

        stack.Push(4);
        REQUIRE(stack.Max() == 4);

        stack.Push(5);
        REQUIRE(stack.Max() == 5);

        stack.Push(4);
        REQUIRE(stack.Max() == 5);

        stack.Push(3);
        REQUIRE(stack.Max() == 5);

        stack.Push(2);
        REQUIRE(stack.Max() == 5);

        stack.Push(1);
        REQUIRE(stack.Max() == 5);

        stack.Pop();
        REQUIRE(stack.Max() == 5);

        stack.Pop();
        REQUIRE(stack.Max() == 5);

        stack.Pop();
        REQUIRE(stack.Max() == 5);

        stack.Pop();
        REQUIRE(stack.Max() == 5);

        stack.Pop();
        REQUIRE(stack.Max() == 4);

        stack.Pop();
        REQUIRE(stack.Max() == 3);

        stack.Pop();
        REQUIRE(stack.Max() == 2);

        stack.Pop();
        REQUIRE(stack.Max() == 1);

        stack.Pop();
        REQUIRE(stack.Max() == 0);
    }
}