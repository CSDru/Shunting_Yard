#include "LinkedList.h"
#include "Test.h"
#include "ShuntingYard.h"
#include <iostream>
#include <stdexcept>

void runLinkedListTests()
{
    LinkedList<int> list;

    // Test empty list
    std::cout << "Testing empty list: " << (list.empty() ? "Passed" : "Failed") << std::endl;

    // Test push_front
    list.push_front(10);
    std::cout << "After push_front(10), front: " << list.front() << " (Expected: 10)" << std::endl;

    // Test push_back
    list.push_back(20);
    std::cout << "After push_back(20), back: " << list.back() << " (Expected: 20)" << std::endl;

    // Test size
    std::cout << "Size of list: " << list.size() << " (Expected: 2)" << std::endl;

    // Test contains
    std::cout << "Contains 10: " << (list.contains(10) ? "Passed" : "Failed") << std::endl;
    std::cout << "Contains 30: " << (list.contains(30) ? "Passed" : "Failed") << std::endl;

    // Test pop_front
    list.pop_front();
    std::cout << "After pop_front(), front: " << list.front() << " (Expected: 20)" << std::endl;

    // Test pop_back
    list.pop_back();
    std::cout << "After pop_back(), empty: " << (list.empty() ? "Passed" : "Failed") << std::endl;

    // Test push_front with multiple elements
    list.push_front(30);
    list.push_front(40);
    std::cout << "After pushing 30 and 40, front: " << list.front() << " (Expected: 40)" << std::endl;

    // Test insert_before
    list.insert_before(30, 35);
    std::cout << "After insert_before(30, 35), contains 35: " << (list.contains(35) ? "Passed" : "Failed") << std::endl;

    // Test insert_after
    list.insert_after(30, 45);
    std::cout << "After insert_after(30, 45), contains 45: " << (list.contains(45) ? "Passed" : "Failed") << std::endl;

    // Test remove
    list.remove(35);
    std::cout << "After remove(35), contains 35: " << (list.contains(35) ? "Passed" : "Failed") << std::endl;

    // Test assignment operator
    LinkedList<int> anotherList = list;
    std::cout << "After assignment, anotherList front: " << anotherList.front() << " (Expected: 40)" << std::endl;

    // Test copy constructor
    LinkedList<int> copyList(list);
    std::cout << "After copy constructor, copyList front: " << copyList.front() << " (Expected: 40)" << std::endl;

    // Test + operator
    LinkedList<int> combinedList = list + anotherList;
    std::cout << "Combined list size: " << combinedList.size() << " (Expected: 6)" << std::endl;

    // Test ostream operator
    std::cout << "List: " << list << std::endl;
}

void runShuntingYardTests() {
    ShuntingYard shuntingYard;

    try {
        std::string expression1 = "3 + 4 * 2 / ( 1 - 5 )";
        std::cout << "Infix: " << expression1 << std::endl;
        std::cout << "Postfix: " << shuntingYard.infixToPostfix(expression1) << std::endl;

        std::string expression2 = "( 1 + 2 ) * 3";
        std::cout << "Infix: " << expression2 << std::endl;
        std::cout << "Postfix: " << shuntingYard.infixToPostfix(expression2) << std::endl;

        std::string expression3 = "10 + 2 * 6";
        std::cout << "Infix: " << expression3 << std::endl;
        std::cout << "Postfix: " << shuntingYard.infixToPostfix(expression3) << std::endl;

        std::string expression4 = "100 * 2 + 12";
        std::cout << "Infix: " << expression4 << std::endl;
        std::cout << "Postfix: " << shuntingYard.infixToPostfix(expression4) << std::endl;

        std::string expression5 = "100 * ( 2 + 12 )";
        std::cout << "Infix: " << expression5 << std::endl;
        std::cout << "Postfix: " << shuntingYard.infixToPostfix(expression5) << std::endl;

        std::string expression6 = "100 * ( 2 + 12 ) / 14";
        std::cout << "Infix: " << expression6 << std::endl;
        std::cout << "Postfix: " << shuntingYard.infixToPostfix(expression6) << std::endl;

    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
