#include "stack/NextGreaterElement.h"
#include <stack>
#include <unordered_map>
using std::stack;
using std::unordered_map;

bool NextGreaterElementI::solve()
{
    return nextGreaterElement(m_nums1, m_nums2).size();
}

// LeetCode 496. Next Greater Element I
vector<int> NextGreaterElementI::nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, int> numResMap;
    stack<int> s;
    
    for (int i = nums2.size() - 1; i >= 0; --i)
    {
        while (!s.empty() && nums2[i] >= s.top()) s.pop();
        numResMap[nums2[i]] = (s.empty() ? -1 : s.top());
        s.push(nums2[i]);
    }

    vector<int> res;
    for (int n : nums1) res.push_back(numResMap[n]);
    return res;
}

bool NextGreaterElementII::solve()
{
    return nextGreaterElements(m_nums).size();
}

// LeetCode 503. Next Greater Element II
// µ¥µ÷Õ»
vector<int> NextGreaterElementII::nextGreaterElements(vector<int>& nums)
{
    int nSzie = nums.size();
    vector<int> res(nSzie, -1);
    stack<int> s;
    for (int i = 2 * nSzie - 1; i >= 0; --i)
    {
        int nIndex = i % nSzie;
        while (!s.empty() && nums[nIndex] >= s.top()) s.pop();
        res[nIndex] = (s.empty() ? -1 : s.top());
        s.push(nums[nIndex]);
    }
    return res;
}

bool NextGreaterElementIII::solve()
{
    return nextGreaterElement(m_n);
}

// LeetCode 556. Next Greater Element III
int NextGreaterElementIII::nextGreaterElement(int n)
{
    int nRes;
    return nRes;
}
