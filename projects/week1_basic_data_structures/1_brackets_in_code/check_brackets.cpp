#include <iostream>
#include "check_brackets.hpp"

std::string check_brackets(const std::string& text) {
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        Bracket l_bracket(next, position);

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(l_bracket);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            auto top = opening_brackets_stack.top();
            if (!top.Matchc(next)) {
                return std::to_string(top.position);
            }
        }
    }// position
    return "Success";
}