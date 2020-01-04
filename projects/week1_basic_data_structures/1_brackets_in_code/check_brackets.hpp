#ifndef CHECK_BRACKETS_H
#define CHECK_BRACKETS_H

#include <string>
#include <iostream>
#include <stack>

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

std::string check_brackets(const std::string& text);

#endif