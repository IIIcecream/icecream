#include "stack/LongestValidParentheses.h"
#include <stack>
#include <vector>
#include "ACMMathCommon.h"

bool LongestValidParentheses::solve()
{
    longestValidParentheses(m_str);
    return true;
}

int LongestValidParentheses::longestValidParentheses(string s)
{
    // �ⷨ1�� ջ
    stack<int> stack;
    int nBegin = 0, res = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(') stack.push(i);
        else
            if (stack.empty()) nBegin = i + 1;
            else
            {
                stack.pop();
                res = stack.empty() ? ACM::max(res, (i - nBegin + 1)) : ACM::max(res, i - stack.top());
            }
    }
    return res;

    // �ⷨ2 dp dp[i]����s[i]�����Ч����
    // ���s[i]Ϊ '(' ������Ч�ģ�dp[i] = 0
    // ����1. s[i - 1]Ϊ'('��dp[i] += dp[i-2] + 2
    //      2. s[i - 1]Ϊ')'����s[i - dp[i - 1] - 1]Ϊ'('���� dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2
    vector<int> dp(s.length(), 0);
    for (size_t i = 1; i < s.length(); ++i)
    {
        int pos = i - dp[i - 1] - 1;
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
            {
                if (i > 1) dp[i] = dp[i - 2] + 2;
                else dp[i] = 2;
            }
            else if(pos >= 0 && s[pos] == '(')
            {
                dp[i] = dp[i - 1] + 2;
                if (pos > 0) dp[i] += dp[pos - 1];
            }
        }
    }
    return ACM::max(dp);
}
