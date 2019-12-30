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
    // ά��һ����СΪk����С�ѣ����նѶ���Ԫ�ؼ�Ϊ��K���
    priority_queue<int, vector<int>, std::greater<int>> minHeap;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        minHeap.push(nums[i]);
        if (i >= k) minHeap.pop();
    }

    return minHeap.top();
}

// ʹ�ÿ���parition˼��
int findKthLargest2(vector<int>& nums, int k)
{
    return -1;
}

int partition(vector<int> &nums, int left, int right)
{
    int privot = nums[left];

    while (left < right)
    {
        while (left < right && nums[left] < privot) ++left;
        std::swap(nums[left], nums[right]);

        while (left < right && nums[right] > privot) --right;
        std::swap(nums[left], nums[right]);
    }

    return left;
}