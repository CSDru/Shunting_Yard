//
// Created by Dru on 9/26/2024.
//

#include "RPN.h"

double RPN::evaluate(const std::string& expression) {
    Stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (std::isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && std::isdigit(token[1]))) {
            // If the token is a number, push it onto the stack
            stack.push(std::stod(token));
        } else if (token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
            // If the token is an operator
            if (stack.size() < 2) {
                throw std::runtime_error("Not enough operands in the stack for operation.");
            }
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            double result = applyOperation(a, b, token[0]);
            stack.push(result);
        } else {
            throw std::runtime_error("Invalid token encountered.");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("The expression is invalid.");
    }

    return stack.top();
}

double RPN::applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Cannot divide by zero.");
            }
            return a / b;
        default:
            throw std::runtime_error("Invalid operator.");
    }
}
