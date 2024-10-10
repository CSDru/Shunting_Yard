//
// Created by Dru on 10/10/2024.
//

#include "ShuntingYard.h"
#include <sstream>

int ShuntingYard::precedence(char op) const
{
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

bool ShuntingYard::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

std::string ShuntingYard::infixToPostfix(const std::string& expression)
{
    std::stack<char> operators;
    std::queue<std::string> output;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        // If the token is a number, add it to the output queue
        if (std::isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && std::isdigit(token[1])))
        {
            output.push(token);
        }
            // If the token is an operator
        else if (isOperator(token[0]))
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token[0]))
            {
                output.push(std::string(1, operators.top()));
                operators.pop();
            }
            operators.push(token[0]);
        }
            // Handle parentheses
        else if (token[0] == '(')
        {
            operators.push('(');
        }
        else if (token[0] == ')') {
            while (!operators.empty() && operators.top() != '(')
            {
                output.push(std::string(1, operators.top()));
                operators.pop();
            }
            if (operators.empty())
            {
                throw std::runtime_error("Mismatched parentheses");
            }
            operators.pop(); // Remove the '(' from the stack
        }
        else
        {
            throw std::runtime_error("Invalid token encountered");
        }
    }

    // Pop all the operators left in the stack
    while (!operators.empty())
    {
        if (operators.top() == '(')
        {
            throw std::runtime_error("Mismatched parentheses");
        }
        output.push(std::string(1, operators.top()));
        operators.pop();
    }

    // Construct the postfix expression
    std::string postfix;
    while (!output.empty())
    {
        postfix += output.front() + " ";
        output.pop();
    }

    return postfix;
}
