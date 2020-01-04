#include <iostream>
#include "check_brackets.hpp"

int main() {
    std::string text;
    getline(std::cin, text);

    // Printing answer, write your code here
    std::cout << check_brackets(text) << std::endl;
    return 0;
}
