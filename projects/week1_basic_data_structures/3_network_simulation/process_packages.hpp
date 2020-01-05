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
        size_ = 0;
        return Response(false, 0);
    }
private:
    int size_;
    std::queue <int> finish_time_;
};

std::vector <Request> ReadRequests();
std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer);
void PrintResponses(const std::vector <Response> &responses);

#endif