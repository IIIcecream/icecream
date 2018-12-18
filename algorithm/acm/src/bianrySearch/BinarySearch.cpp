#include "BinarySearch\binarySearch.h"

// ���ֲ���
int BinarySearch::binarySearch(std::vector<int> &nums, int nLow, int nHigh, int nTarget)
{
    while (nLow <= nHigh)
    {
        int mid = nLow + (nHigh - nLow) / 2;//�����������
        if (nums[mid] > nTarget)
            nHigh = mid - 1;
        else if (nums[mid] < nTarget)
            nLow = mid + 1;
        else
            return mid;
    }
    return-1;
}

// ���ֲ��� �ݹ�ʵ��
//int BinarySearch::binarySearch(std::vector<int> &nums, int nLow, int nHigh, int nTarget)
//{
//    if (nLow > nHigh) return -1;
//    if (nLow == nHigh) return nums[nLow] == nTarget ? nLow : -1;
//    int nMid = (nLow + nHigh) / 2;
//    if (nums[nMid] == nTarget) return nMid;
//    else if (nums[nMid] > nTarget) return binarySearch(nums, nLow, nMid, nTarget);
//    else return binarySearch(nums, nMid + 1, nHigh, nTarget);
//}

