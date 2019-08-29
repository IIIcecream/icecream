#include "others/CompareStringsbyFrequencyoftheSmallestCharacter.h"
#include <algorithm>

bool CompareStringsbyFrequencyoftheSmallestCharacter::solve()
{

    return true;
}

// LeetCode 1170. Compare Strings by Frequency of the Smallest Character
vector<int> CompareStringsbyFrequencyoftheSmallestCharacter::numSmallerByFrequency(vector<string>& queries, vector<string>& words)
{
    vector<int> wordsVal(words.size(), 0);

    int i = 0;
    for (string s : words)
    {
        wordsVal[i++] = getVal(s);
    }
    std::sort(wordsVal.begin(), wordsVal.end());


    vector<int> res(queries.size(), 0);
    i = 0;
    for (size_t i = 0; i < queries.size(); ++i)
    {
        auto it = std::upper_bound(wordsVal.begin(), wordsVal.end(), getVal(queries[i]));
        res[i] = wordsVal.end() - it;
    }
    return res;
}

int CompareStringsbyFrequencyoftheSmallestCharacter::getVal(string &s)
{
    vector<int> charactor(26, 0);
    int nMinChar = 27;
    for (char c : s)
    {
        charactor[c - 'a']++;
        if (c - 'a' < nMinChar) nMinChar = c - 'a';
    }
    return charactor[nMinChar];
}

