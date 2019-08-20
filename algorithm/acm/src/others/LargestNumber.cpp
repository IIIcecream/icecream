#include "others/LargestNumber.h"
#include <algorithm>

bool LargestNumber::solve()
{
    largestNumber(m_nums);
    return true;
}

// LeetCode 179 Largest Number
string LargestNumber::largestNumber(vector<int>& nums)
{
    vector<string> numstring(nums.size(), "");
    for (size_t i = 0; i < nums.size(); ++i)
    {
        numstring[i] = std::to_string(nums[i]);
    }

    std::sort(numstring.begin(), numstring.end(), [this](string &left, string &right)->bool
    {
        string s1 = left + right;
        string s2 = right + left;
        return s1 > s2;
    });

    if (numstring[0] == "0") return "0";

    string sRes;
    for (size_t i = 0; i < numstring.size(); ++i) sRes += numstring[i];

    return sRes;
}