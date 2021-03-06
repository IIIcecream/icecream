#include "graph/CloneGraph.h"

bool CloneGraph::solve()
{
    return true;
}

// LeetCode 133. Clone Graph
// 感觉不能使用val作为key，因为不同节点的val可能是相同的
GraphNode * CloneGraph::cloneGraph(GraphNode* node)
{
    if (!node) return nullptr;

    // 该邻居节点已经被构造过了
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
