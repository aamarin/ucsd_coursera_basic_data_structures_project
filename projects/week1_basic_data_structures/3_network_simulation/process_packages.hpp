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
        // std::cout << "New Process() call, new arrival time: " << request.arrival_time << std::endl;

        if(finish_time_.empty()) {
            // std::cout << "(empty queue) Response arrival time: " << request.arrival_time << ", finish time pushed in: " << request.arrival_time + request.process_time << std::endl;
            finish_time_.push(request.arrival_time + request.process_time);
            return Response(false, request.arrival_time);
        }

        while (!finish_time_.empty() && request.arrival_time >= finish_time_.front())
        {
            // std::cout << "DROPPED " << finish_time_.front() << std::endl;
            finish_time_.pop();
        }

        if(size_ == finish_time_.size()) {
            // std::cout << "Buffer full, dropping packet" << finish_time_.front() << std::endl;
            return Response(true, request.arrival_time);
        }

        if(request.arrival_time > finish_time_.back()) {
            // std::cout << "(not empty queue), arrive > finish.back(), Response arrival time: " << request.arrival_time << ", finish time pushed in: " << request.arrival_time + request.process_time << std::endl;
            finish_time_.push(request.arrival_time + request.process_time);
            return Response(false, request.arrival_time);;
        }

        // std::cout << "(not empty queue) Response arrival time: " << finish_time_.back() << ", finish time pushed in: " << finish_time_.back() + request.process_time << std::endl;
        Response response(false, finish_time_.back());
        finish_time_.push(finish_time_.back() + request.process_time);
        return response;
    }

private:
    int size_;
    std::queue <int> finish_time_;
};

void ReadRequests(const std::string& fileName, int& outBufferSize, std::vector<Request>& outRequest);
std::vector<Response> ProcessRequests(const std::vector<Request>& requests, Buffer *buffer);
std::vector<int> CreateResponseOutput(const std::vector <Response>& responses);

#endif