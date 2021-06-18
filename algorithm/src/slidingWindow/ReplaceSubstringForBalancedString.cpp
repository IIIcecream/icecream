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

    // ���󣬺��ң��ҵ�һ�����ܵ���Сֵ���п��ܲ������Ž⣩
    while (std::max({ str['Q'], str['W'], str['E'], str['R'] }) <= target && str[s[i]] + 1 <= target && j >= i) str[s[i++]]++;
    while (std::max({ str['Q'], str['W'], str['E'], str['R'] }) <= target && str[s[j]] + 1 <= target && j >= i) str[s[j--]]++;
    ans = std::min(ans, j - i + 1);

    // ��������õĽ�Ļ����ϣ��޶��������ڵĴ�С���������Ž⡣���ﲻ�����һ����ˣ���Ϊans��ʱ�Ѿ��Ǵ�����������Ž�
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

