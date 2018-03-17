#pragma once
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include "Lexeme.h"

class CalculatorClass
{
public:
	void GetExpression(std::string data, std::vector<char> operatorList);
	void ShowOriginalExpression();
	void Transform();
	void ShowReversePolish();
	float Calculate();
private:
	Lexeme AdditionSubstraction(Lexeme leftOperand, Lexeme rightOperand,Lexeme Operator);
	Lexeme MultiplicationDivision(Lexeme leftOperand, Lexeme rightOperand, Lexeme Operator);
	std::vector<Lexeme> reversePolish;
	std::vector<Lexeme> expression;

};