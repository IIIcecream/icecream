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
            // ����left�Ѿ�����
            if (deque.front() == i - k) deque.pop_front();
            // �½���Ԫ�أ������±����ֵ����ֵС�ģ�ȫ��β��������
            while (nums[i] > nums[deque.back()]) deque.pop_back();
        }

        // β���������±�
        deque.push_back(i);
        if (i + 1 >= k) res.push_back(nums[deque.front()]);
    }

    return res;
}

