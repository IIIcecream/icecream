#include "stack/BasicCalculator.h"

#include <stack>
using std::stack;

bool BasicCalculator::solve()
{
    return calculate(m_sStr);
}

// LeetCode 224. Basic Calculator
int BasicCalculator::calculate(string s)
{
    if (s.empty()) return 0;
    s = "(" + s + ")";
    int pos[] = { 0 };
    return calculate(s, pos);
}

int BasicCalculator::calculate(string s, int pos[])
{
    int val = 0, i = pos[0], sign = 1, num = 0;

    while (i < s.length()) {
        char c = s[i];
        switch (c) {
        case '+': val = val + sign * num; num = 0; sign = 1; i++; break;
        case '-': val = val + sign * num; num = 0; sign = -1; i++; break;
        case '(': pos[0] = i + 1; val = val + sign * calculate(s, pos); i = pos[0]; break;
        case ')': pos[0] = i + 1; return val + sign * num;
        case ' ': i++; continue;
        default: num = num * 10 + c - '0'; i++;
        }
    }

    return val;
}

int BasicCalculator::calculate2(string s)
{
    stack<int> num;
    int res = 0, sign = 1, i = 0;
    while (i < s.size()) {
        if (isdigit(s[i])) {
            int cur = s[i] - '0';
            while (isdigit(s[++i]) && i < s.size()) {
                cur = cur * 10 + (s[i] - '0');
            }
            res = res + sign * cur;
        }
        else if (s[i] == '+') {
            sign = 1;
            i++;
        }
        else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (s[i] == '(') {
            num.push(res);
            num.push(sign);
            sign = 1;
            res = 0;
            i++;
        }
        else if (s[i] == ')') {
            sign = num.top();
            num.pop();
            res = num.top() + sign * res;
            num.pop();
            i++;
        }
        else i++;
    }
    return res;
}

