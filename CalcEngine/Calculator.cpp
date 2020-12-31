#include "Calculator.h"
#include <stdexcept>
#include <cmath>
using namespace std;

Calculator::Calculator() {
    num1 = 0;
    num2 = 0;
    oper = NONE;
}

void Calculator::setOper(opType operand)
{
    oper = operand;
}
void Calculator::setNum1(double number)
{
    num1 = number;
}
void Calculator::setNum2(double number){
    num2 = number;
}
void Calculator::store(double value) {
    if (num1 == 0.0)
    {
        num1 = num2;
        num2 = value;
    }
    else
    {
        num2 = value;
    }
}

double Calculator::handleOperation(Calculator::opType newOperation) {
    if (newOperation == ADD)
    {
        if (num1 != 0.0)
        {
            equalsPressed();
            oper = ADD;
            return num1;
        }
        oper = ADD;
        num1 = num2;
        return num1;
    }
    else if (newOperation == SUBTRACT)
    {
        if (num1 != 0.0)
        {
            equalsPressed();
            oper = SUBTRACT;
            return num1;
        }
        oper = SUBTRACT;
        num1 = num2;
        return num1;
    }
    else if (newOperation == MULTIPLY)
    {
        if (num1 != 0.0)
        {
            equalsPressed();
            oper = MULTIPLY;
            return num1;
        }
        oper = MULTIPLY;
        num1 = num2;
        return num1;
    }
    else if (newOperation == DIVIDE)
    {
        if (num1 != 0.0)
        {
            equalsPressed();
            oper = DIVIDE;
            return num1;
        }
        oper = DIVIDE;
        num1 = num2;
        return num1;
    }
    else if (newOperation == SQRT)
    {
        num2 = sqrt(num2);
        return num2;
    }
}

double Calculator::equalsPressed() {
    if (oper == ADD)
    {
        num1 += num2;
        return num1;
    }
    else if (oper == SUBTRACT)
    {
        num1 -= num2;
        return num1;
    }
    else if (oper == MULTIPLY)
    {
        num1 *= num2;
        return num1;
    }
    else if (oper == DIVIDE)
    {
        num1 /= num2;
        return num1;
    }
    else if (oper == SQRT)
    {
        num2 = sqrt(num2);
        return num2;
    }
}

void Calculator::clear() {
    num1 = 0;
    num2 = 0;
    oper = NONE;
}
