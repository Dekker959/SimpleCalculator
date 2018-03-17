#include "stdafx.h"
#include "Lexeme.h"
#include <utility> 

Lexeme::Lexeme()
	:value(""),isOperator(NULL)
{
}

Lexeme Lexeme::operator+(Lexeme const & rightOperand)
{
	if (this->isOperator)
	{
		this->value += value;
	}
	else
	{
		this->value=std::to_string(std::stof(this->value) + std::stof(rightOperand.value));
	}
	return *this;
}

Lexeme Lexeme::operator-(Lexeme const & rightOperand)
{
	if (this->isOperator)
	{
		this->value += value;
	}
	else
	{
		this->value = std::to_string(std::stof(this->value) - std::stof(rightOperand.value));
	}
	return *this;
}

Lexeme Lexeme::operator*(Lexeme const & rightOperand)
{
	if (this->isOperator)
	{
		this->value += value;
	}
	else
	{
		this->value = std::to_string(std::stof(this->value) * std::stof(rightOperand.value));
	}
	return *this;
}

Lexeme Lexeme::operator/(Lexeme const & rightOperand)
{
	if (this->isOperator)
	{
		this->value += value;
	}
	else
	{
		this->value = std::to_string(std::stof(this->value) / std::stof(rightOperand.value));
	}
	return *this;
}


void Lexeme::SetPriority()
{
	if (!this->isOperator)
	{
		return;
	}

	if (this->value == "+" || this->value == "-")
	{
		this->priority = AddSubstract;
	}
	if (this->value == "*" || this->value == "/")
	{
		this->priority = MultDivision;
	}
	if (this->value == "(" )
	{
		this->priority = BracketOpen;
	}
	if (this->value == ")")
	{
		this->priority = BracketClose;
	}
}