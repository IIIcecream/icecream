#include "slidingWindow\LongestRepeatingCharacterReplacement.h"
#include <vector>
#include "ACMMathCommon.h"
using namespace std;

bool LongestRepeatingCharacterReplacement::solve()
{
    return characterReplacement(m_s, m_nK);
}

// leetcode T424 Longest Repeating Character Replacement     
int LongestRepeatingCharacterReplacement::characterReplacement(string s, int k)
{
    int nRes = 0, nLeft = 0, nMax = 0;
    vector<int> nums(26, 0);

    for (int nRight = 0; nRight < s.length(); ++nRight)
    {
        nMax = ACM::max(nMax, ++nums[s[nRight] - 'A']);

        while (nMax + k < nRight - nLeft + 1) nums[s[nLeft++]-'A']--;
        nRes = ACM::max(nRes, nRight - nLeft + 1);
    }

    return nRes;
}

