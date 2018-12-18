#include "binarySearch\SearchInRotatedSortedArray.h"

bool SearchInRotatedSortedArray::solve()
{
    search(m_nums, m_nTarget);
    return true;
}

// ������ת�������� LeetCode T33
int SearchInRotatedSortedArray::search(vector<int>& nums, int target)
{
    return binarySearch(0, nums.size() - 1, target);
}

// ���֣����п϶���һ��������ģ���һ������������ģ����target����������Ǳߣ������������Ķ��֣���һ������ ��һ����������
int SearchInRotatedSortedArray::binarySearch(int nLow, int nHigh, int nTarget)
{
    if (nLow > nHigh) return -1;
    if (nLow == nHigh) return m_nums[nLow] == nTarget ? nLow : -1;
    int nMid = (nLow + nHigh) / 2;
    if (m_nums[nMid] == nTarget) return nMid;
    // �������
    if (m_nums[nLow] <= m_nums[nMid])
    {
        if (m_nums[nLow] <= nTarget && nTarget <= m_nums[nMid])
            return BinarySearch::binarySearch(m_nums, nLow, nMid, nTarget);
        else
            return binarySearch(nMid + 1, nHigh, nTarget);
    }
    // �ұ�����
    else
    {
        if (m_nums[nMid] <= nTarget && nTarget <= m_nums[nHigh])
            return BinarySearch::binarySearch(m_nums, nLow, nMid, nTarget);
        else
            return binarySearch(nLow, nMid, nTarget);
    }
}

