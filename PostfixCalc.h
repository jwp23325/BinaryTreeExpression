#define _CRT_SECURE_NO_WARNINGS
#ifndef PFCALC_H
#define PFCALC_H


//#include "myStack.h"
#include <string>
#include <stack>

using namespace std;

class postFixCalc
{
public:
	// Precondition - postfix expression string is provided
	// Postcondition - string is stored in class
	void setPostFixExp(string);

	// Postconition - Returns the expression string
	string getPostFixExp();

	// Precondition - Assumes the expression has been stored in the class
	// Postcondition - THe expression has been evaluated
	// and the result is stored on the stack
	void evaluate();

	// Precondition - The operator character is provided
	// Postcondition - The top two numbers on the stck are evaluated
	// and the result is stored back on the stack, exceptions are thrown
	// if the specified error conditions are detected
	void evaluateOpr(char);
	/*
		throw (TooFewOperandsException,
			DivisionByZeroException,
			IllegalOperatorException); */

			// Precondition - The expresion has been evaluated and 
			// the result is the only item in the stack
			// Postcondition - the result is returned, exceptions are thrown if the 
			// specified error conditions are detected
	double getResult(); //throw (TooManyOperandsException, ErrorinExpressionException);


	class TooFewOperandsException {
	public:
		TooFewOperandsException() { message = "Not enough operndds "; }
		string what() { return message; }
	private:
		string message;
	};

	class DivisionByZeroException {
	public:
		DivisionByZeroException() { message = "Division by 0 "; }
		string what() { return message; }
	private:
		string message;
	};

	class IllegalOperatorException {
	public:
		IllegalOperatorException() { message = "Illegal operator "; }
		string what() { return message; }
	private:
		string message;
	};


	class TooManyOperandsException {
	public:
		TooManyOperandsException() { message = "Too many operands "; }
		string what() { return message; }
	private:
		string message;
	};


	class ErrorinExpressionException {
	public:
		ErrorinExpressionException() { message = "Illegal operator "; }
		string what() { return message; }
	private:
		string message;
	};

private:
	string pFexp;
	stack <double> resultStack;
	char* expression;
};
#endif