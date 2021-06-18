#include "graph/WordLadder.h"
#include "graph/GraphCommon.h"
#include <queue>
#include <map>

bool WordLadder::solve()
{
    ladderLength();
    return true;
}

// 单词接龙 LeetCode T127
// 先将起终点单词、list中的单词，当成节点，每两个差一个单词的节点连接，构成图
// 然后求起终点在图中的最短距离，BFS
int WordLadder::ladderLength()
{
    int nBegin = 0, nEnd = 0;
    bool bBeginExist = false, bEndExist = false;
    for (int i = 0; i < (int)m_words.size(); ++i)
    {
        if (m_words[i] == m_sBeginWord) bBeginExist = true, nBegin = i;
        if (m_words[i] == m_sEndWord) bEndExist = true, nEnd = i;
    }
    if (!bEndExist) return 0;

    if (!bBeginExist) m_words.push_back(m_sBeginWord), nBegin = m_words.size() - 1;

    // 构造邻接矩阵二维数组
    map<int, vector<int>> Matrix;
    int nSize = m_words.size();

    for (int i = 0; i < nSize; ++i)
        for (int j = i + 1; j < nSize; ++j)
            if (canLink(m_words[i], m_words[j]))
                Matrix[i].push_back(j), Matrix[j].push_back(i);

    //记录顶点是否被访问
    vector<int> vexs(nSize, 0);
    // BFS
    int nRes = 0;
    queue<int> nodes;
    nodes.push(nBegin);
    vexs[nBegin] = 1;

    while (!nodes.empty())
    {
        ++nRes;
        int nCount = nodes.size();
        for (int i = 0; i < nCount; ++i)
        {
            int nCurNode = nodes.front();
            nodes.pop();
            for (size_t j = 0; j < Matrix[nCurNode].size(); ++j)
            {
                int nNextNode = Matrix[nCurNode][j];
                if (nNextNode == nEnd)  return ++nRes;
                if (!vexs[nNextNode]) nodes.push(nNextNode), vexs[nNextNode] = 1;
            }
        }
    }
    return 0;
}


// 判断两个单词是否只相差一个字母(长度一致）
bool WordLadder::canLink(string s1, string s2)
{
    int num = 0;
    for (size_t i = 0; i < s1.length(); ++i)
    {
        if (s1[i] == s2[i]) num++;
    }
    return num == s1.length() - 1;
}
