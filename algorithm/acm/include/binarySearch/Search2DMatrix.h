#pragma once
#include "binarySearch.h"

// Search a 2D Matrix
class Search2DMatrix : public BinarySearch
{
public:
    virtual bool solve() override;

private:
    bool binarySearch(int **arr, int nLow, int nHigh, int nTarget, int nCol);
    bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target);

private:
    int nRow;
    int nColumn;
};