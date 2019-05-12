#include "slidingWindow\SlidingWindowMedian.h"
#include <set>

bool SlidingWindowMedian::solve()
{
    medianSlidingWindow(m_nums, m_nK);
    return true;
}

// LeetCode 480 Sliding Window Median
// 主要思路就是利用两个set来排序，一个set放较小的数，一个set放较大的数，那中位数肯定就在 small的最大元素和 large最小元素中产生（或许是两个的平均数）
// 窗口滑动过程中，当元素要从窗口左侧出来时，从set中删除该元素
vector<double> SlidingWindowMedian::medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> res;
    multiset<int> small, large;

    for (int i = 0; i < (int)nums.size(); ++i)
    {
        // 需要删除窗口左侧数据
        if (i >= k)
        {
            if (small.count(nums[i - k])) small.erase(small.find(nums[i - k]));
            else large.erase(large.find(nums[i - k]));
        }

        if (small.size() <= large.size())
        {
            if (large.empty() || nums[i] <= *large.begin()) small.insert(nums[i]);
            else
            {
                large.insert(nums[i]);
                small.insert(*large.begin());
                large.erase(large.begin());
            }
        }
        else
        {
            if (nums[i] >= *small.rbegin()) large.insert(nums[i]);
            else
            {
                small.insert(nums[i]);
                large.insert(*small.rbegin());
                small.erase(--small.end());
            }
        }

        if (i >= (k - 1))
        {
            if (small.size() > large.size()) res.push_back(*small.rbegin());
            else res.push_back(*small.rbegin() * 0.5 + *large.begin() * 0.5);   //这里不能先相加再*0.5，int会越界
        }
    }

    return res;
}

