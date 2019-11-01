#include "others/QueueReconstructionByHeight.h"
#include <algorithm>

bool QueueReconstructionByHeight::solve()
{
    return reconstructQueue(m_people).size();
}

// LeetCode 406. Queue Reconstruction by Height
vector<vector<int>> QueueReconstructionByHeight::reconstructQueue(vector<vector<int>>& people)
{
    std::sort(people.begin(), people.end(), [](vector<int>& lhs, vector<int>& rhs) {
        return lhs[0] > rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
    });

    vector<vector<int>> res;
    for (vector<int>& item : people)
    {
        res.insert(res.begin() + item[1], move(item));
    }

    return res;
}

