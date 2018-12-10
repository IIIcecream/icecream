#pragma once
#include <vector>
#include "IACM.h"
using namespace std;

class SolutionBinaSrh : public IACM
{
public:
    virtual bool solve() override;

private:
    bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target);

    bool binarySearch(int **arr, int nLow, int nHigh, int nTarget, int row);

    int nRow;
    int nColumn;
};