#include "stack\LargestRectangleInHistogram.h"
#include <stack>
#include "ACMMathCommon.h"

bool LargestRectangleInHistogram::solve()
{
    return largestRectangleArea(m_heights);
}

// LeetCode 84 Largest Rectangle in Histogram
// ����ջ
int LargestRectangleInHistogram::largestRectangleArea(vector<int>& heights)
{
    int nRes = 0;
    heights.push_back(0);

    stack<int> myStack;

    for (size_t i = 0; i < heights.size(); ++i)
    {
        // ���ֵ�ǰԪ�ر�ջ��Ԫ��Сʱ��ջ����Ҫ���㵱ǰ�߶ȵ����(ע�⣬�������Ҫ�㵽ǰһ��Ԫ�أ���pop����±�)��Ȼ���ջ
        while (!myStack.empty() && heights[i] < heights[myStack.top()])
        {
            int nHeight = heights[myStack.top()];
            myStack.pop();
            nRes = ACM::max(nRes, nHeight * (myStack.empty() ? i : (i - myStack.top() - 1)));
        }
        myStack.push(i);
    }
    return nRes;
}

