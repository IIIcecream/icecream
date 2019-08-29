#pragma once

#include "IACM.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class CompareStringsbyFrequencyoftheSmallestCharacter : public IACM
{
public:
    CompareStringsbyFrequencyoftheSmallestCharacter(vector<string>& queries, vector<string>& words);
    virtual bool solve() override;

private:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words);
    int getVal(string &s);

private:

};