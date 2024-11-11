#define _CRT_SECURE_NO_WARNINGS
#include "binaryExpressionTree.h"
#include <stack>
#include <stdexcept>
#include <cstdlib>  // For std::stod


// Constructor
binaryExpressionTree::binaryExpressionTree() : binaryTreeType() {}

// Build the expression tree from a postfix expression
void binaryExpressionTree::buildExpressionTree(const std::string& postfix) {
    std::stack<nodeType<std::string>*> stack;
    char* token;
    char* expression = new char[postfix.length() + 1];
    std::strcpy(expression, postfix.c_str());

    token = std::strtok(expression, " ");
    while (token != nullptr) {
        std::string tokenStr(token);  // Convert token from a character array to a string
        if (isdigit(token[0])) {
            nodeType<std::string>* newNode = new nodeType<std::string>();  // Create a new node
            std::string tokenStr(token);  // Convert token from a character array to a string
            newNode->info = tokenStr;  // Store token in the info field of the node
            newNode->lLink = newNode->rLink = nullptr;  // Set both links to nullptr for now
            stack.push(newNode);  // Push the new node onto the stack                                                // If it's a number, push to the stack
        }
        else if (tokenStr == "+" || tokenStr == "-" || tokenStr == "*" || tokenStr == "/") {
            nodeType<std::string>* newNode = new nodeType<std::string>();  // Create a new node for the operator
            newNode->info = token;  // Store the operator in the info field

            if (!stack.empty()) {
                newNode->rLink = stack.top();  // Right child is the top node on the stack
                stack.pop();  // Pop the top node from the stack

                if (!stack.empty()) {
                    newNode->lLink = stack.top();       // Store the reference of the left operand in lLink
                    stack.pop();                        // Pop the new top node from the stack
                    stack.push(newNode);  // Push operator node back onto stack
                }

                else {
                    throw std::runtime_error("Error: Stack is empty (invalid expression).");
                }

            }

            else {
                throw std::runtime_error("Error: Stack is empty (invalid expression).");
            }

        }

        else {
            throw std::runtime_error("Error: Unsupported token encountered.");
        }

        token = std::strtok(nullptr, " ");
    }

    if (!stack.empty()) {
        root = stack.top();
        stack.pop();

        if (!stack.empty()) {
            root = nullptr;
            throw std::runtime_error("Error: Stack not empty after building expression tree.");
        }
    }

    delete[] expression;
}

// Evaluate the expression tree recursively
double binaryExpressionTree::evaluateExpressionTree() {
    return evaluateExpressionTree(root);
}

double binaryExpressionTree::evaluateExpressionTree(nodeType<std::string>* node) {
    if (!node->lLink && !node->rLink) {  // Leaf node, must be an operand
        return std::stod(node->info);  // Convert string to double
    }

    double leftVal = evaluateExpressionTree(node->lLink);
    double rightVal = evaluateExpressionTree(node->rLink);
    std::string op = node->info;

    if (op == "+") return leftVal + rightVal;
    else if (op == "-") return leftVal - rightVal;
    else if (op == "*") return leftVal * rightVal;
    else if (op == "/") return leftVal / rightVal;
    
    throw std::runtime_error("Error: Invalid operator in expression tree.");
}

// Trivial methods to fulfill the base class requirements
bool binaryExpressionTree::search(const std::string&) const {
    return false;  // Not implemented
}

void binaryExpressionTree::insert(const std::string&) {
    // Not implemented
}

void binaryExpressionTree::deleteNode(const std::string&) {
    // Not implemented
}

