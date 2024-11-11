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
	void setPostFixExp(string);

	string getPostFixExp();

	void evaluate();

	void evaluateOpr(char);
	/*
		throw (TooFewOperandsException,
			DivisionByZeroException,
			IllegalOperatorException); */

	double getResult(); //throw (TooManyOperandsException, ErrorinExpressionException);


	class TooFewOperandsException {
	public:
		TooFewOperandsException() { message = "Not enough operndds ";  }
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
