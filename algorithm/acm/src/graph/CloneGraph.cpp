#include "graph\CloneGraph.h"

bool CloneGraph::solve()
{
    return true;
}

// LeetCode 133. Clone Graph
// �о�����ʹ��val��Ϊkey����Ϊ��ͬ�ڵ��val��������ͬ��
GraphNode * CloneGraph::cloneGraph(GraphNode* node)
{
    if (!node) return nullptr;

    // ���ھӽڵ��Ѿ����������
    if (nodeMap.count(node) > 0)
    {
        return nodeMap[node];
    }

    GraphNode *pRes = new GraphNode(node->val, vector<GraphNode*>(node->neighbors.size(), nullptr));
    nodeMap[node] = pRes;

    for (size_t i = 0; i < node->neighbors.size(); ++i)
        pRes->neighbors[i] = cloneGraph(node->neighbors[i]);

    return pRes;
}
