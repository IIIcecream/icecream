#include "stack\GenerateParentheses.h"
#include <stack>
using namespace std;
// Generate Parentheses LeetCode T22
bool GenerateParentheses::solve()
{
    backtrack("", 0, 0);
    return true;
}

// 使用回溯法
void GenerateParentheses::backtrack(std::string cur, int open, int close)
{
    if (close > open) return;
    if (cur.length() == m_n * 2)
    {
        m_res.push_back(cur);
        return;
    }

    if (open < m_n) backtrack(cur + "(", open + 1, close);
    if (close < m_n) backtrack(cur + ")", open, close + 1);
}
