#include "binarySearch\binarySearch.h"
#include <iostream>

bool SolutionBinaSrh::solve()
{
    try
    {
        int *b = new int[4], *c = new int[4], *d = new int[4];
        b[0] = 1, b[1] = 3, b[2] = 5, b[3] = 7;
        c[0] = 10, c[1] = 310, c[2] = 510, c[3] = 10;
        d[0] = 10, d[1] = 10, d[2] = 10, d[3] = 10;
        int **a = new(int *[2]);
        a[0] = b;
        a[1] = c;
        a[2] = d;

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 4; ++j) cout << a[i][j] << endl;

        cout << &a[0][0] << "\t" << &a[1][0] << "\t" << &a[2][0] << endl;
        for (int i = 0; i < 12; ++i) cout << *(*a + i) << endl;
        cout << searchMatrix(a, 3, 4, 5);
    }
    catch (const std::exception&)
    {
        return false;
    }

    return true;
}

bool SolutionBinaSrh::searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    if (matrixRowSize == 0 || matrixColSize == 0) return false;
    return binarySearch(matrix, 0, matrixColSize * matrixRowSize - 1, target, matrixColSize);
}

bool SolutionBinaSrh::binarySearch(int **arr, int nLow, int nHigh, int nTarget, int nCol)
{
    if (nHigh == nLow + 1) return arr[nLow / nCol][nLow % nCol] == nTarget || arr[nHigh / nCol][nHigh % nCol] == nTarget;
    if (nHigh == nLow) return arr[nLow / nCol][nLow % nCol] == nTarget;
    int nMid = (nHigh + nLow) * 0.5, nVal = arr[nMid / nCol][nMid % nCol];
    if (nVal == nTarget) return true;
    else if (nVal > nTarget) return binarySearch(arr, nLow, nMid, nTarget, nCol);
    else return binarySearch(arr, nMid, nHigh, nTarget, nCol);
}