//
// Created by Dru on 9/26/2024.
//

#ifndef SHUNTING_YARD_RPN_H
#define SHUNTING_YARD_RPN_H

#include "Queue.h"
#include "Stack.h"
#include <string>
#include <sstream>
#include <stdexcept>

class RPN {
public:
    // Evaluate the RPN expression
    double evaluate(const std::string& expression);

private:
    // Helper function to apply an operation
    double applyOperation(double a, double b, char op);
};

#endif // SHUNTING_YARD_RPN_H
