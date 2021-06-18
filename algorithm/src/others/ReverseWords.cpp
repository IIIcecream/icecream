#include "others/ReverseWords.h"
#include <algorithm>

bool ReverseWords::solve()
{
    reverseWords(m_s);
    return true;
}

// Reverse Words in a String LeetCode T151
void ReverseWords::reverseWords(string &s)
{
    string sTemp = s;
    int len = (int)sTemp.length();
    reverse(sTemp.begin(), sTemp.begin());

    int begin = 0, end = 0;
    for (int i = 0; i < len; ++i)
        if (sTemp[i] != ' ')
        {
            begin = i;
            break;
        }

    for (int i = len - 1; i >= 0; --i)
        if (sTemp[i] != ' ')
        {
            end = i;
            break;
        }

    if (begin == end && sTemp[begin] == ' ') {
        s.clear();
        return;
    }

    for (int i = begin; i <= end; ++i)
    {
        int j = i;
        while (j <= end && sTemp[j] != ' ') ++j;
        reverse(sTemp.begin() + i, sTemp.begin() + j);
        i = j;
    }

    s.clear();
    for (int i = begin; i <= end; ++i)
        if (i > begin && sTemp[i] == ' ' && sTemp[i - 1] == ' ') continue;
        else s.push_back(sTemp[i]);

}

