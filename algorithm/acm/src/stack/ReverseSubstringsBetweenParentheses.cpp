#include "stack/ReverseSubstringsBetweenParentheses.h"
#include <stack>
using std::stack;

bool ReverseSubstringsBetweenParentheses::solve()
{
    return reverseParentheses(m_str).size();
}

string ReverseSubstringsBetweenParentheses::reverseParentheses(string& s)
{
    string sRes;
    stack<char> symbol;
    stack<char> stackOfChar;

    for (char c : s)
    {
        if (c == '(')
        {
            symbol.push(c);
        }
        else if (c == ')')
        {
            symbol.pop();
        }
        else
        {

        }
    }
    
    return sRes;
}