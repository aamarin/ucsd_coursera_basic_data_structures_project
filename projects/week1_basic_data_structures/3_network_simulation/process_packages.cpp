#include <iostream>
#include <fstream>
#include <string>
#include "process_packages.hpp"

 void ReadRequests(const std::string& fileName, int& outBufferSize, std::vector<Request>& outRequest) {
    std::ifstream infile(fileName);
    outRequest.clear();

    int bufferSize, numIncomingPackets;
    infile >> bufferSize >> numIncomingPackets;

    for (int i = 0; i < numIncomingPackets; ++i) {
        int arrival_time, process_time;
        infile >> arrival_time >> process_time;
        outRequest.push_back(Request(arrival_time, process_time));
    }

    outBufferSize = bufferSize;
}

std::vector<Response> ProcessRequests(const std::vector<Request>& requests, Buffer *buffer) {
    std::vector<Response> responses;
    for (int i = 0; i < requests.size(); ++i)
         responses.push_back(buffer->Process(requests[i]));

    return responses;
}