#include "slidingWindow\SlidingWindowMedian.h"
#include <set>

bool SlidingWindowMedian::solve()
{
    medianSlidingWindow(m_nums, m_nK);
    return true;
}

// LeetCode 480 Sliding Window Median
// ��Ҫ˼·������������set������һ��set�Ž�С������һ��set�Žϴ����������λ���϶����� small�����Ԫ�غ� large��СԪ���в�����������������ƽ������
// ���ڻ��������У���Ԫ��Ҫ�Ӵ���������ʱ����set��ɾ����Ԫ��
vector<double> SlidingWindowMedian::medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> res;
    multiset<int> small, large;

    for (int i = 0; i < (int)nums.size(); ++i)
    {
        // ��Ҫɾ�������������
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
            else res.push_back(*small.rbegin() * 0.5 + *large.begin() * 0.5);   //���ﲻ���������*0.5��int��Խ��
        }
    }

    return res;
}

