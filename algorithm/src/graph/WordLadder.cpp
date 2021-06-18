#include "graph/WordLadder.h"
#include "graph/GraphCommon.h"
#include <queue>
#include <map>

bool WordLadder::solve()
{
    ladderLength();
    return true;
}

// ���ʽ��� LeetCode T127
// �Ƚ����յ㵥�ʡ�list�еĵ��ʣ����ɽڵ㣬ÿ������һ�����ʵĽڵ����ӣ�����ͼ
// Ȼ�������յ���ͼ�е���̾��룬BFS
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

    // �����ڽӾ����ά����
    map<int, vector<int>> Matrix;
    int nSize = m_words.size();

    for (int i = 0; i < nSize; ++i)
        for (int j = i + 1; j < nSize; ++j)
            if (canLink(m_words[i], m_words[j]))
                Matrix[i].push_back(j), Matrix[j].push_back(i);

    //��¼�����Ƿ񱻷���
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


// �ж����������Ƿ�ֻ���һ����ĸ(����һ�£�
bool WordLadder::canLink(string s1, string s2)
{
    int num = 0;
    for (size_t i = 0; i < s1.length(); ++i)
    {
        if (s1[i] == s2[i]) num++;
    }
    return num == s1.length() - 1;
}
