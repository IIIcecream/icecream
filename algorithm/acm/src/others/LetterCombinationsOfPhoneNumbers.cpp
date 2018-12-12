#include "others\LetterCombinationsOfPhoneNumbers.h"

// 电话号码的字母组合 LeetCode T17
bool LetterCombinationsOfPhoneNumbers::solve()
{
    if (m_strNums.empty()) return false;
    doCombination(m_strNums, 0, string());
    return true;
}

void LetterCombinationsOfPhoneNumbers::doCombination(string &digits, int cur, string s)
{
    if (cur == digits.length()) {
        m_res.push_back(s);
        return;
    }

    vector<char> &curVec = m_map[digits[cur] - 48];
    for (int i = 0; i < (int)curVec.size(); ++i)
    {
        s.push_back(curVec[i]);
        doCombination(digits, cur + 1, s);
        s.pop_back();
    }
}

void LetterCombinationsOfPhoneNumbers::initMap()
{
    vector<char> num3char(3, 'a'), num4char(4, 'a');
    
    // 2
    num3char[1] = 'b';
    num3char[2] = 'c';
    m_map[2] = num3char;
    // 3
    num3char[0] = 'd';
    num3char[1] = 'e';
    num3char[2] = 'f';
    m_map[3] = num3char;
    // 4
    num3char[0] = 'g';
    num3char[1] = 'h';
    num3char[2] = 'i';
    m_map[4] = num3char;
    // 5
    num3char[0] = 'j';
    num3char[1] = 'k';
    num3char[2] = 'l';
    m_map[5] = num3char;
    // 6
    num3char[0] = 'm';
    num3char[1] = 'n';
    num3char[2] = 'o';
    m_map[6] = num3char;
    // 7
    num4char[0] = 'p';
    num4char[1] = 'q';
    num4char[2] = 'r';
    num4char[3] = 's';
    m_map[7] = num4char;
    // 8
    num3char[0] = 't';
    num3char[1] = 'u';
    num3char[2] = 'v';
    m_map[8] = num3char;
    // 9
    num4char[0] = 'w';
    num4char[1] = 'x';
    num4char[2] = 'y';
    num4char[3] = 'z';
    m_map[9] = num4char;
}

