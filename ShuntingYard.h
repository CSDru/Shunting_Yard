//
// Created by Dru on 10/10/2024.
//

#ifndef SHUNTING_YARD_SHUNTINGYARD_H
#define SHUNTING_YARD_SHUNTINGYARD_H


#include <string>
#include <stack>
#include <queue>
#include <stdexcept>

class ShuntingYard
{
public:
    // Convert an infix expression to postfix notation
    std::string infixToPostfix(const std::string& expression);

private:
    // Function to determine the precedence of operators
    int precedence(char op) const;

    // Function to check if a character is an operator
    bool isOperator(char c) const;
};


#endif //SHUNTING_YARD_SHUNTINGYARD_H
