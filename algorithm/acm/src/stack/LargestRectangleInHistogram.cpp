#include "stack\LargestRectangleInHistogram.h"
#include <stack>
#include "ACMMathCommon.h"

bool LargestRectangleInHistogram::solve()
{
    return largestRectangleArea(m_heights);
}

// LeetCode 84 Largest Rectangle in Histogram
// 单调栈
int LargestRectangleInHistogram::largestRectangleArea(vector<int>& heights)
{
    int nRes = 0;
    heights.push_back(0);

    stack<int> myStack;

    for (size_t i = 0; i < heights.size(); ++i)
    {
        // 出现当前元素比栈顶元素小时，栈顶需要结算当前高度的面积(注意，这里面积要算到前一个元素，即pop后的下标)，然后出栈
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

