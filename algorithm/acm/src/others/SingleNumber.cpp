#include "others\SingleNumber.h"
#include <set>

bool SingleNumber::solve()
{
    singleNumber(m_nums);
    return true;
}

int SingleNumber::singleNumber(vector<int>& nums)
{
    int n = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) n ^= nums[i];
    return n;
}

bool SingleNumber2::solve()
{
    singleNumber(m_nums);
    return true;
}

int SingleNumber2::singleNumber(vector<int>& nums)
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
