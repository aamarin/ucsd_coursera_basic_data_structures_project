#include <iostream>
#include "check_brackets.hpp"

std::string check_brackets(const std::string& text) {
    std::stack <Bracket> opening_brackets_stack;

    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        Bracket l_bracket(next, position + 1);

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket
            if(text.length() == 1) return std::to_string(position + 1);
            opening_brackets_stack.push(l_bracket);
        }

        else {
            // Process closing bracket
            if(opening_brackets_stack.empty()) return std::to_string(position + 1);

            auto top = opening_brackets_stack.top();
            opening_brackets_stack.pop();

            if( !top.Matchc(next) ) return std::to_string(top.position + 1);
        }// else
    }// position

    return (std::string("Success"));
}