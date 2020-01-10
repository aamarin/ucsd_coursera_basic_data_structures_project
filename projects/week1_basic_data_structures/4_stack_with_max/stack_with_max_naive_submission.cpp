#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    std::stack<int> max;

  public:
    StackWithMax() = default;

    void Push(int value) {
        //std::cout << "Push " << value << std::endl;
        if(!max.empty() && value < max.top()) {
            stack.push_back(value);
            //std::cout << "max.top: " << max.top() << " stack.top: " << stack.back() << std::endl;
            return;
        }

        max.push(value);
        stack.push_back(value);
        //std::cout << "stack_aux.top: " << max.top() << " stack.top: " << stack.back() << std::endl;
    }

    void Pop() {
        //std::cout << "Pop " << stack.back() << std::endl;
        assert(stack.size() && max.size());
        if(stack.back() == max.top()) {
            //std::cout << "Popped largest value" << std::endl;
            max.pop();
        }

        stack.pop_back();
        //std::cout << "stack_aux.top: " << max.top() << " stack.top: " << stack.back() << std::endl;
    }

    int Max() const {
        assert(stack.size() && max.size());
        return max.top();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}