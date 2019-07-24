#pragma once
#include "IACM.h"
#include <vector>
#include <map>
#include "tree\binaryTree\binaryTreeCommon.h"
using namespace std;

// ¥Úº“ΩŸ…·
class HouseRobber : public IACM
{
public:
    HouseRobber(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    int rob(vector<int>& nums);
    int rob2(vector<int>& nums);
    int rob3(TreeNode* root);

private:
    vector<int> m_nums;
    map<TreeNode*, int> robMap;
};