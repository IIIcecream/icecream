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

bool SingleNumberIII::solve()
{
    singleNumber(m_nums);
    return true;
}

// LeetCode 260 Single NumberIII
vector<int> SingleNumberIII::singleNumber(vector<int>& nums)
{
    // 解法2
    int nXOR = 0;
    for (int n : nums) nXOR ^= n;

    int nOneIndex = 0, nTemp = nXOR; // 找到nXOR从右到左第一个非0的位
    while (nTemp)
    {
        if (nTemp % 2) break;
        nOneIndex++;
        nTemp >>= 1;
    }

    // 找到数组中所有该位为1的数字，与nXOR求异或
    int res1 = nXOR;
    for (int n : nums)
    {
        if ((n >> nOneIndex) % 2) res1 ^= n;
    }

    vector<int> res;
    res.push_back(res1);
    res.push_back(res1 ^ nXOR);

    return res;


    // 解法2
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
