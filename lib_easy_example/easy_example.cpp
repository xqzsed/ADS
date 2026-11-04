// Copyright 2024 Marina Usova

#include <stdexcept>
#include "../lib_easy_example/easy_example.h"
#include "../lib_stack_on_mass/stack.h"
#include <cstring>

float division(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Input Error: can't divide by zero!");
    }
    return static_cast<float>(a) / b;
}

bool check_breckets(std::string expression) {
    TStackOnMass<char> top_stack(expression.size());

    for (char a : expression) {
        if (a == '(' || a == '{' || a == '[') {
            top_stack.push(a);
        }
        else if (a == ')' || a == '}' || a == ']') {
            if (top_stack.is_empty()) {
                return false;
            }

            char top = top_stack.pop();

            if (a == ')' && top != '(') return false;
            if (a == '}' && top != '{') return false;
            if (a == ']' && top != '[') return false;
        }
    }

    return top_stack.is_empty();
}