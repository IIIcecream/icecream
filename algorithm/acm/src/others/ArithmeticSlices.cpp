#include "others/ArithmeticSlices.h"

bool ArithmeticSlices::solve()
{
    return numberOfArithmeticSlices(m_vec);
}

// LeetCode 413. Arithmetic Slices
int ArithmeticSlices::numberOfArithmeticSlices(vector<int>& A)
{
    int nRes = 0, nSize = A.size();
    if (nSize < 2) return nRes;

    int len = 0;
    for (int i = 2; i < A.size(); ++i)
    {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
        {
            ++len;
        }
        else
        {
            nRes += (1 + len) * len / 2;
            len = 0;
        }
    }
    return nRes + len * (len + 1 ) / 2;
}

