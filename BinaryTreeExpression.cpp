#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include "PostfixCalc.h"
#include "binaryExpressionTree.h"  
#include "binaryTree.h"  


using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    binaryExpressionTree expTree;                                                   // Create an object of binaryExpressionTree to evaluate

    // Open the input file containing potfix expressions
    inputFile.open("RpnData.txt");
    if (!inputFile) {
        cout << "Cannot open the input file. "
            << "Program terminates!" << endl;
        return 1;
    }

    // Open the output file for writing evaluation results
    outputFile.open("RpnOutput.txt");
    if (!outputFile) {
        cout << "Cannot open the output file. "
            << "Program terminates!" << endl;
        return 1;
    }

    outputFile << fixed << showpoint;
    outputFile << setprecision(2);                                                  // Set output formatting to 2 decimal places
 
    binaryExpressionTree exprTree;                                                  // Object to manage the currect expression tree
    string expr;                                                                    // Stores each postfix expresion read from file
    postFixCalc calc;                                                               // Calculator object for additional functionality, if needed
    double result;                                                                  // Stores the evaluation result of the current expression
   
    // Read each line (expression) from the input file
    while (getline(inputFile, expr)) {
        try {
            exprTree.buildExpressionTree(expr);                                     // Build the expression tree from the postfix expresion string
            double result = exprTree.evaluateExpressionTree();                      // Evaluate the expresion tree from the postfix expression string
            outputFile << "Expression: " << expr << " = " << result << endl;        // Write the result to the output file
            exprTree.destroyTree();                                                 // Clear the current tree to prepare for the next expression
        }

        // Catch and handle specific exceptions related to postix calculations
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
    

