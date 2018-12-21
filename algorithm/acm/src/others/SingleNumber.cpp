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
    // 解法1： 第一个数时，b等于该数，a等于0；第二个相同数时，b等于0，a等于该数；第三个相同数时，a、b都为0.
    int a = 0, b = 0;
    for (auto num : nums)
    {
        b = ~a & (b ^ num);
        a = ~b & (a ^ num);
    }
    return b;

    //解法2：记录每一位（32位数）上出现1的次数，如果%3不为0，说明这位上的1来自于单独的那个数
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
