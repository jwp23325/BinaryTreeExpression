#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include "PostfixCalc.h"
#include "binaryExpressionTree.h"  // Make sure to include your expression tree header
#include "binaryTree.h"  // Include binaryTree.h since it's the base class


using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    binaryExpressionTree expTree; // Create an object of binaryExpressionTree to evaluate

    inputFile.open("RpnData.txt");
    if (!inputFile) {
        cout << "Cannot open the input file. "
            << "Program terminates!" << endl;
        return 1;
    }

    outputFile.open("RpnOutput.txt");
    if (!outputFile) {
        cout << "Cannot open the output file. "
            << "Program terminates!" << endl;
        return 1;
    }

    outputFile << fixed << showpoint;
    outputFile << setprecision(2);
    
    // Create an object of binaryExpressionTree
    binaryExpressionTree exprTree;
    string expr;

    postFixCalc calc;
    double result;
    getline(inputFile, expr);

    while (getline(inputFile, expr)) {
        try {
            // Build and evaluate the expression tree
            exprTree.buildExpressionTree(expr);
            double result = exprTree.evaluateExpressionTree();

            // Output the result to the file
            outputFile << "Expression: " << expr << " = " << result << endl;

            // Clear the current expression tree
            exprTree.destroyTree();
        }
        catch (const runtime_error& e) {
            outputFile << "Error evaluating expression: " << expr << endl;
            cerr << e.what() << endl;
        }
        catch (postFixCalc::TooFewOperandsException e) {
            outputFile << "Error evaluating expression: Too few operands." << endl;
        }
        catch (postFixCalc::DivisionByZeroException e) {
            outputFile << "Error evaluating expression: Division by zero." << endl;
        }
        catch (postFixCalc::IllegalOperatorException e) {
            outputFile << "Error evaluating expression: Illegal operator." << endl;
        }
        catch (postFixCalc::TooManyOperandsException e) {
            outputFile << "Error evaluating expression: Too many operands." << endl;
        }
        catch (postFixCalc::ErrorinExpressionException e) {
            outputFile << "Error evaluating expression: Invalid expression." << endl;
        }
        catch (const exception e) {
            outputFile << "Unexpected error: " << e.what() << endl;
        }
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    cout << "Evaluation complete. Results written to Result.txt" << endl;
    return 0;  // Successful execution
}
    

