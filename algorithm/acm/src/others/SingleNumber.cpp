#include "others\SingleNumber.h"
#include <set>

bool SingleNumber::solve()
{
    singleNumber(m_nums);
    return true;
}

// LeetCode 136 Single Number
int SingleNumber::singleNumber(vector<int>& nums)
{
    int n = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) n ^= nums[i];
    return n;
}

bool SingleNumberII::solve()
{
    singleNumber(m_nums);
    return true;
}

// LeetCode 137 Single NumberII
int SingleNumberII::singleNumber(vector<int>& nums)
{
    // �ⷨ1�� ��һ����ʱ��b���ڸ�����a����0���ڶ�����ͬ��ʱ��b����0��a���ڸ�������������ͬ��ʱ��a��b��Ϊ0.
    int a = 0, b = 0;
    for (auto num : nums)
    {
        b = ~a & (b ^ num);
        a = ~b & (a ^ num);
    }
    return b;

    //�ⷨ2����¼ÿһλ��32λ�����ϳ���1�Ĵ��������%3��Ϊ0��˵����λ�ϵ�1�����ڵ������Ǹ���
    a = 0;
    for (int i = 0; i < 32; ++i)
    {
        b = 0;
        for (size_t j = 0; j < nums.size(); ++j)
            b += (nums[j] >> i) & 1;
        a |= (b % 3) << i;
    }
    return a;
}

bool SingleNumberIII::solve()
{
    singleNumber(m_nums);
    return true;
}

// LeetCode 260 Single NumberIII
vector<int> SingleNumberIII::singleNumber(vector<int>& nums)
{
    // �ⷨ2
    int nXOR = 0;
    for (int n : nums) nXOR ^= n;

    int nOneIndex = 0, nTemp = nXOR; // �ҵ�nXOR���ҵ����һ����0��λ
    while (nTemp)
    {
        if (nTemp % 2) break;
        nOneIndex++;
        nTemp >>= 1;
    }

    // �ҵ����������и�λΪ1�����֣���nXOR�����
    int res1 = nXOR;
    for (int n : nums)
    {
        if ((n >> nOneIndex) % 2) res1 ^= n;
    }

    vector<int> res;
    res.push_back(res1);
    res.push_back(res1 ^ nXOR);

    return res;


    // �ⷨ2
    int val = 0;
    for (int n : nums) val ^= n;

    nOneIndex = 0;
    for (int i = 0; i < 32; i++)
    {
        if (val & (1 << i))
        {
            nOneIndex = i;
            break;
        }
    }
    int mask = 1 << nOneIndex, a = 0, b = 0;
    for (int n : nums)
    {
        if (mask & n) a ^= n;
        else b ^= n;
    }
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}
