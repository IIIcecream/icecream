#include "stack\MyCalculator.h"
#include <stack>
using namespace std;

MyCalculator::~MyCalculator()
{
    int i = 0;
}

bool MyCalculator::solve()
{
    calculate(m_str);
    return true;
}

// Basic Calculator LeetCode 224
int MyCalculator::calculate(string s)
{
    stack<int> numStack;
    stack<char> symbolStack;

    int nCur = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if(bNum(s[i])) nCur = nCur * 10 + s[i] - '0';
        else if (bSymbol(s[i]))
        {
            symbolStack.push(s[i]);
        }
        else
        {

        }
    }

    return 1;
}

bool MyCalculator::bNum(char c)
{
    return (c >= '0' && c <= '9');
}

bool MyCalculator::bSymbol(char c)
{
    return c == '-' || c == '+';
}