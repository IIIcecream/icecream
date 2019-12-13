#include "heap/KthLargestElementInArray.h"
#include <queue>
using std::priority_queue;

bool KthLargestElementInArray::solve()
{
    throw std::logic_error("The method or operation is not implemented.");
}

// LeetCode 215 Kth Largest Element In an Array
int KthLargestElementInArray::findKthLargest(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, std::greater<int>> minHeap;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        minHeap.push(nums[i]);
        if (i >= k) minHeap.pop();
    }

    return minHeap.top();
}

