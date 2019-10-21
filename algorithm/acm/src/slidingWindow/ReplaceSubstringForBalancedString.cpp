#include "slidingWindow/ReplaceSubstringForBalancedString.h"
#include <algorithm>

bool ReplaceSubstringForBalancedString::solve()
{
    return lengthOfLongestSubstring(m_str);
}

// LeetCode 5232. Replace the Substring for Balanced String
int ReplaceSubstringForBalancedString::lengthOfLongestSubstring(string s)
{
    int ans = s.size(), target = ans / 4, i = 0, j = ans - 1;
    int str[100] = {0};

    // 先左，后右，找到一个可能的最小值（有可能不是最优解）
    while (std::max({ str['Q'], str['W'], str['E'], str['R'] }) <= target && str[s[i]] + 1 <= target && j >= i) str[s[i++]]++;
    while (std::max({ str['Q'], str['W'], str['E'], str['R'] }) <= target && str[s[j]] + 1 <= target && j >= i) str[s[j--]]++;
    ans = std::min(ans, j - i + 1);

    // 在上面求得的解的基础上，限定滑动窗口的大小，再求最优解。这里不用往右滑动了，因为ans此时已经是从右往左的最优解
    while (i > 0) {
        str[s[--i]]--;
        str[s[j--]]++;
        while (std::max({ str['Q'], str['W'], str['E'], str['R'] }) <= target && j > 0 && str[s[j]] + 1 <= target && j >= i) {
            str[s[j--]]++;
            ans = std::min(ans, j - i + 1);
        }
    }

    return ans;
}

