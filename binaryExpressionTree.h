#define _CRT_SECURE_NO_WARNINGS
#ifndef H_BINARYEXPRESSIONTREE
#define H_BINARYEXPRESSIONTREE


#include "binaryTree.h" // Include the base class
#include <string>

class binaryExpressionTree : public binaryTreeType<std::string> {
public:
    // Constructor
    binaryExpressionTree();  

    // Build the expression tree from a postfix expression
    void buildExpressionTree(const std::string& postfix);

    // Evaluate the expression tree
    double evaluateExpressionTree();

    // Trivial search, insert, and deleteNode implementations
    bool search(const std::string&) const override;
    void insert(const std::string&) override;
    void deleteNode(const std::string&) override;

private:
    // Helper function to evaluate the expression tree recursively
    double evaluateExpressionTree(nodeType<std::string>* node);
};

#endif


