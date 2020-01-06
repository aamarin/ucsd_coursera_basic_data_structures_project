#include <fstream>
#include <iostream>
#include <algorithm>

#include "catch.hpp"
#include "process_packages.hpp"

bool passedCheck(const std::string& fileName, const std::vector<Response>& expected) {
    int size = 0;
    std::vector<Request> request_list;
    ReadRequests(fileName, size, request_list);

    Buffer buffer(size);
    const std::vector<Response> responses = ProcessRequests(request_list, &buffer);

    return (responses == expected);
}

std::vector<Response> createExpectedResponse(const std::string& fileName) {
    std::ifstream infile(fileName);
    std::vector<Response> responses;
    int output = 0;
    while(infile >> output) {
        responses.push_back(Response(output == -1, output));
    }

    return responses;
}

TEST_CASE("Testing process_packages", "[process_packages]") {
    {
        std::vector<Response> EXPECTED = createExpectedResponse("tests/01.a");
        REQUIRE( passedCheck("tests/01", EXPECTED) );
    }
}