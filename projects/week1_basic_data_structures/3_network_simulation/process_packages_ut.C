#include <fstream>
#include <iostream>
#include <algorithm>

#include "catch.hpp"
#include "process_packages.hpp"

bool passedCheck(const std::string& fileName, const std::vector<int>& expected) {
    int size = 0;
    std::vector<Request> request_list;
    ReadRequests(fileName, size, request_list);

    Buffer buffer(size);
    const std::vector<Response> responses = ProcessRequests(request_list, &buffer);
    const std::vector<int> outputResponse = CreateResponseOutput(responses);
    REQUIRE(outputResponse == expected);
    return (outputResponse == expected);
}

std::vector<int> createExpectedOutput(const std::string& fileName) {
    std::ifstream infile(fileName);
    std::vector<int> responses;
    int output = 0;
    while(infile >> output) {
        responses.push_back(output);
    }

    return responses;
}

TEST_CASE("Testing process_packages", "[process_packages]") {
    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/01.a");
        REQUIRE( passedCheck("tests/01", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/02.a");
        REQUIRE( passedCheck("tests/02", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/03.a");
        REQUIRE( passedCheck("tests/03", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/04.a");
        REQUIRE( passedCheck("tests/04", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/05.a");
        REQUIRE( passedCheck("tests/05", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/06.a");
        REQUIRE( passedCheck("tests/06", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/07.a");
        REQUIRE( passedCheck("tests/07", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/08.a");
        REQUIRE( passedCheck("tests/08", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/09.a");
        REQUIRE( passedCheck("tests/09", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/10.a");
        REQUIRE( passedCheck("tests/10", EXPECTED) );
    }

        {
        std::vector<int> EXPECTED = createExpectedOutput("tests/11.a");
        REQUIRE( passedCheck("tests/11", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/12.a");
        REQUIRE( passedCheck("tests/12", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/13.a");
        REQUIRE( passedCheck("tests/13", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/14.a");
        REQUIRE( passedCheck("tests/14", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/15.a");
        REQUIRE( passedCheck("tests/15", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/16.a");
        REQUIRE( passedCheck("tests/16", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/17.a");
        REQUIRE( passedCheck("tests/17", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/18.a");
        REQUIRE( passedCheck("tests/18", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/19.a");
        REQUIRE( passedCheck("tests/19", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/20.a");
        REQUIRE( passedCheck("tests/20", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/21.a");
        REQUIRE( passedCheck("tests/21", EXPECTED) );
    }

    {
        std::vector<int> EXPECTED = createExpectedOutput("tests/22.a");
        REQUIRE( passedCheck("tests/22", EXPECTED) );
    }
}