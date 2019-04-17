#include "slidingWindow\SlidingWindowMaximum.h"
#include "ACMMathCommon.h"
#include <deque>

bool SlidingWindowMaximum::solve()
{
    maxSlidingWindow(m_nums, m_nK);
    return true;
}

// LeetCode 239 Sliding Window Maximum
vector<int> SlidingWindowMaximum::maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> res;
    deque<int> deque;

    for (int i = 0; i < (int)nums.size(); ++i)
    {
        if (!deque.empty())
        {
            // 窗口left已经滑过
            if (deque.front() == i - k) deque.pop_front();
            // 新进入元素，将该下标出的值比新值小的，全从尾部出队列
            while (nums[i] > nums[deque.back()]) deque.pop_back();
        }

        // 尾部插入新下标
        deque.push_back(i);
        if (i + 1 >= k) res.push_back(nums[deque.front()]);
    }

    return res;
}

