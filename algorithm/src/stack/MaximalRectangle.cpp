#include "stack/MaximalRectangle.h"
#include "ACMMathCommon.h"
#include "stack/LargestRectangleInHistogram.h"

bool MaximalRectangle::solve()
{
    return maximalRectangle(m_matrix);
}

// LeetCode 85 Maximal Rectangle
int MaximalRectangle::maximalRectangle(vector<vector<char>>& matrix)
{
    int nRes = 0;
    if (matrix.empty()) return nRes;

    vector<int> heights(matrix[0].size() + 1, 0);

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] != '0') heights[j]++;
            else heights[j] = 0;
        }
        nRes = ACM::max(nRes, LargestRectangleInHistogram(heights).largestRectangleArea(heights));
    }

    return nRes;
}

