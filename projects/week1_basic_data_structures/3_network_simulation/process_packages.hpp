#ifndef PROCESS_PACKAGES_H
#define PROCESS_PACKAGES_H
#include <queue>
#include <vector>

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool operator==(const Response& l) const {
        return (l.dropped == dropped &&
        l.start_time == start_time);
    }

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
        finish_time_()
    {}

    Response Process(const Request &request) {
        // write your code here
        std::cout << size_ << std::endl;
        std::cout << finish_time_.empty() << std::endl;
        return Response(false, 0);
    }
private:
    int size_;
    std::queue <int> finish_time_;
};

void ReadRequests(const std::string& fileName, int& outBufferSize, std::vector<Request>& outRequest);
std::vector<Response> ProcessRequests(const std::vector<Request>& requests, Buffer *buffer);

#endif