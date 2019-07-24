#include "graph\CloneGraph.h"

bool CloneGraph::solve()
{
    return true;
}

// LeetCode 133. Clone Graph
// �о�����ʹ��val��Ϊkey����Ϊ��ͬ�ڵ��val��������ͬ��
Node * CloneGraph::cloneGraph(Node* node)
{
    if (!node) return nullptr;

    // ���ھӽڵ��Ѿ����������
    if (nodeMap.count(node) > 0)
    {
        return nodeMap[node];
    }

    Node *pRes = new Node(node->val, vector<Node*>(node->neighbors.size(), nullptr));
    nodeMap[node] = pRes;

    for (size_t i = 0; i < node->neighbors.size(); ++i)
        pRes->neighbors[i] = cloneGraph(node->neighbors[i]);

    return pRes;
}
