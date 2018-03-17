#include "stdafx.h"
#include "CalculatorClass.h"

void CalculatorClass::GetExpression(std::string data, std::vector<char> operatorList)
{
	int length = data.size();
	Lexeme operatorLexeme, operandLexeme;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < operatorList.size(); j++)
		{
			if (data[i] == operatorList[j])
			{
				if(operandLexeme.value!="") this->expression.push_back(operandLexeme);
				operandLexeme.value = "";
				operatorLexeme.value = data[i];
				operatorLexeme.isOperator = true;
				operatorLexeme.SetPriority();
				this->expression.push_back(operatorLexeme);
				break;
			}
			else
			{
				if (j == (operatorList.size() - 1))
				{
					operandLexeme.value += data[i];
					operandLexeme.isOperator = false;
				}
			}
		}
	}
	if (operandLexeme.value != "") this->expression.push_back(operandLexeme);
}

void CalculatorClass::ShowOriginalExpression()
{
	for (int i = 0; i < this->expression.size(); i++)
	{
		std::cout << this->expression[i].value;
	}
	std::cout << std::endl;
}

void CalculatorClass::Transform()
{
	std::stack<Lexeme> Buffer;
	for (int i = 0; i < this->expression.size(); i++)
	{
		switch (this->expression[i].priority)
		{
		case Lexeme::BracketOpen:
			Buffer.push(this->expression[i]);
			break;
		case Lexeme::BracketClose:
			while (Buffer.top().priority != Lexeme::BracketOpen)
			{
				this->reversePolish.push_back(Buffer.top());
				Buffer.pop();
			}
			Buffer.pop();
			break;
		case Lexeme::AddSubstract:
			while (Buffer.size()!=0 && Buffer.top().priority!=Lexeme::BracketOpen)
			{
					this->reversePolish.push_back(Buffer.top());
					Buffer.pop();
			}

			Buffer.push(this->expression[i]);
			break;
		case Lexeme::MultDivision:
			if (Buffer.size() != 0 && Buffer.top().priority != Lexeme::BracketOpen)
			{
				if (Buffer.top().priority >= this->expression[i].priority)
				{
					this->reversePolish.push_back(Buffer.top());
					Buffer.pop();
					Buffer.push(this->expression[i]);
				}
				else
				{
					Buffer.push(this->expression[i]);
				}
			}
			else
			{
				Buffer.push(this->expression[i]);
			}
			break;
		default:
			this->reversePolish.push_back(this->expression[i]);
			break;
		}
	}
	while (Buffer.size()!=0)
	{
		this->reversePolish.push_back(Buffer.top());
		Buffer.pop();
	}
}

void CalculatorClass::ShowReversePolish()
{
	for (int i = 0; i < this->reversePolish.size(); i++)
	{
		std::cout << this->reversePolish[i].value;
	}
	std::cout << std::endl;
}

float CalculatorClass::Calculate()
{
	std::stack<Lexeme> buffer;
	Lexeme lOperand, rOperand;
	for (int i = 0; i < this->reversePolish.size(); i++)
	{
		if (!this->reversePolish[i].isOperator)
		{
			buffer.push(this->reversePolish[i]);
		}
		else
		{
			switch (this->reversePolish[i].priority)
			{
			case Lexeme::AddSubstract:
				rOperand = buffer.top();
				buffer.pop();
				lOperand = buffer.top();
				buffer.pop();
				buffer.push(this->AdditionSubstraction(lOperand, rOperand, this->reversePolish[i]));
				break;
			case Lexeme::MultDivision:
				rOperand = buffer.top();
				buffer.pop();
				lOperand = buffer.top();
				buffer.pop();
				buffer.push(this->MultiplicationDivision(lOperand, rOperand, this->reversePolish[i]));
				break;
			default:
				break;
			}
		}
	}
	return std::stof(buffer.top().value);
}

Lexeme CalculatorClass::AdditionSubstraction(Lexeme leftOperand, Lexeme rightOperand, Lexeme Operator)
{
	if (Operator.value == "+")
	{
		return leftOperand + rightOperand;
	}
	else
	{
		return leftOperand - rightOperand;
	}
	//return Lexeme();
}

Lexeme CalculatorClass::MultiplicationDivision(Lexeme leftOperand, Lexeme rightOperand, Lexeme Operator)
{
	if (Operator.value == "*")
	{
		return leftOperand * rightOperand;
	}
	else
	{
		return leftOperand / rightOperand;
	}
}
