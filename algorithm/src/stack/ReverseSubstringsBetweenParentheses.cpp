#include "stack/ReverseSubstringsBetweenParentheses.h"
#include <stack>
using std::stack;

bool ReverseSubstringsBetweenParentheses::solve()
{
    return reverseParentheses(m_str).size();
}

// LeetCode 1190. Reverse Substrings Between Each Pair of Parentheses
string ReverseSubstringsBetweenParentheses::reverseParentheses(string& s)
{
    string sRes;
    stack<char> stackOfChar;

    for (char& c : s)
    {
        if (c == ')')
        {
            while (stackOfChar.top() != '(')
            {
                sRes += stackOfChar.top();
                stackOfChar.pop();
            }
            stackOfChar.pop();  // µ¯³öÕ»¶¥µÄ(

            for (char& cc : sRes)
            {
                stackOfChar.push(cc);
            }
            sRes.clear();
        }
        else
            stackOfChar.push(c);
    }

    while (!stackOfChar.empty())
    {
        sRes += stackOfChar.top();
        stackOfChar.pop();
    }

    std::reverse(sRes.begin(), sRes.end());
    return sRes;
}