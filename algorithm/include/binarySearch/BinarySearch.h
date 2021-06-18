#pragma once
#include <vector>
#include "IACM.h"

class BinarySearch : public IACM
{
public:
    virtual int binarySearch(std::vector<int> &nums, int nLow, int nHigh, int nTarget) {return -1;}
};
