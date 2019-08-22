#pragma once

#include <vector>
#include <map>
#include "IACM.h"
using namespace std;

// ͼ�ڵ�
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

// ��¡ͼ
class CloneGraph : public IACM
{
public:
    virtual bool solve() override;

    GraphNode * cloneGraph(GraphNode* node);

private:
    map <GraphNode *, GraphNode *> nodeMap; //��¼src�ڵ���dest�ڵ��ӳ���ϵ
};