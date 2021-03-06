// calculator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include <string>

#include "CalculatorClass.h"

std::vector<char> operatorList;

int main()
{
	operatorList.push_back('+');
	operatorList.push_back('-');
	operatorList.push_back('*');
	operatorList.push_back('/');
	operatorList.push_back('(');
	operatorList.push_back(')');

	CalculatorClass calc;
	std::string expression;
	std::cin >> expression;
	calc.GetExpression(expression, operatorList);
	calc.ShowOriginalExpression();
	calc.Transform();
	calc.ShowReversePolish();
	float result=calc.Calculate();
	std::cout << result << std::endl;
	std::cout << "complete" << std::endl;
    return 0;
}
