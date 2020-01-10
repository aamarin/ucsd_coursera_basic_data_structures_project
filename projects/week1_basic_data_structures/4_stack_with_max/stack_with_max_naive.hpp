#ifndef STACK_WITH_MAX_H
#define STACK_WITH_MAX_H

#include <vector>
#include <cassert>
#include <stack>
#include <iostream>

using std::vector;

class StackWithMax {
    vector<int> stack;
    std::stack<int> max;

  public:
    StackWithMax() = default;

    void Push(int value) {
        std::cout << "Push " << value << std::endl;
        if(!max.empty() && value < max.top()) {
            stack.push_back(value);
            std::cout << "max.top: " << max.top() << " stack.top: " << stack.back() << std::endl;
            return;
        }

        max.push(value);
        stack.push_back(value);
        std::cout << "stack_aux.top: " << max.top() << " stack.top: " << stack.back() << std::endl;
    }

    void Pop() {
        std::cout << "Pop " << stack.back() << std::endl;
        assert(stack.size() && max.size());
        if(stack.back() == max.top()) {
            std::cout << "Popped largest value" << stack.back() << std::endl;
            max.pop();
        }

        stack.pop_back();
        std::cout << "stack_aux.top: " << max.top() << " stack.top: " << stack.back() << std::endl;
    }

    int Max() const {
        assert(stack.size() && max.size());
        return max.top();
    }
};

#endif