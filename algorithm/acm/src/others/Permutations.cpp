#include "others\Permutations.h"


bool Premutations::solve()
{
    permute(m_nums);
    return true;
}

// ȫ���� LeetCode T46
void Premutations::permute(vector<int>& nums, int pos /*= 0*/)
{
    if (pos == nums.size() - 1) m_res.push_back(nums);

    for (size_t i = pos; i < nums.size(); ++i)
    {
        swap(nums[i], nums[pos]);
        permute(nums, pos + 1);
        swap(nums[i], nums[pos]);
    }
}

// ȫ����II LeetCode T47
void Premutations::permuteUnique(vector<int> &nums, int pos /*= 0*/)
{

}

