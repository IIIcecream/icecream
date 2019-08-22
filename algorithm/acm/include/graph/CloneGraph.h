#pragma once

#include <vector>
#include <map>
#include "IACM.h"
using namespace std;

// 图节点
class GraphNode {
public:
    int val;
    vector<GraphNode*> neighbors;

    GraphNode() {}

    GraphNode(int _val, vector<GraphNode*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// 克隆图
class CloneGraph : public IACM
{
public:
    virtual bool solve() override;

    GraphNode * cloneGraph(GraphNode* node);

private:
    map <GraphNode *, GraphNode *> nodeMap; //记录src节点与dest节点的映射关系
};