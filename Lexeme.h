#pragma once

#include <string>
#include <vector>

class Lexeme
{
public:
	enum Priority
	{
		AddSubstract = 0, MultDivision = 1, BracketOpen=2, BracketClose=3
	};

	Lexeme();
	virtual Lexeme operator + (Lexeme const &rightOperand);
	virtual Lexeme operator - (Lexeme const &rightOperand);
	virtual Lexeme operator * (Lexeme const &rightOperand);
	virtual Lexeme operator / (Lexeme const &rightOperand);

	virtual void SetPriority();
	std::string value;
	bool isOperator;
	Priority priority;
};