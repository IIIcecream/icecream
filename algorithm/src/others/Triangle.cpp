#include "others/Triangle.h"
#include "ACMMathCommon.h"
using namespace std;

// 三角形最小路径和 LeetCode T120
bool Triangle::solve()
{
    int n = m_triangle.size(), res = 2 ^ 31 - 1;
    vector<int> coast(n, 0);

    for (int i = 0; i < n; ++i)
        for (int j = i; j >= 0; --j)
        {
            if (j == 0) coast[j] += m_triangle[i][j];
            else if (j == i) coast[j] = coast[j - 1] + m_triangle[i][j];
            else coast[j] = ACM::min(coast[j - 1], coast[j]) + m_triangle[i][j];

            if (i == n - 1) res = ACM::min(res, coast[j]);
        }

    return true;
}

