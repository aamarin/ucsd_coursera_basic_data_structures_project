#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;

    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        Bracket l_bracket(next, position + 1);

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket
            if(text.length() == 1) {
                std::cout << std::to_string(position + 1) << std::endl;
                return -1;
            }

            opening_brackets_stack.push(l_bracket);
        }

        else if(next == ')' || next == ']' || next == '}') {
            // Process closing bracket
            if(opening_brackets_stack.empty()) {
                std::cout << std::to_string(position + 1) << std::endl;
                return -1;
            }

            auto top = opening_brackets_stack.top();
            opening_brackets_stack.pop();

            if( !top.Matchc(next) ) {
                std::cout << position + 1 << std::endl;
                return -1;
            }
        }// else
    }// position

    if(!opening_brackets_stack.empty()) {
        auto top = opening_brackets_stack.top();
        std::cout << top.position << std::endl;
        return -1;
    }

    std::cout << "Success" << std::endl;
    return 0;
}