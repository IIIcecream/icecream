#pragma once

#include <vector>
#include <map>
#include "IACM.h"
using namespace std;

// 图节点
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// 克隆图
class CloneGraph : public IACM
{
public:
    virtual bool solve() override;

    Node * cloneGraph(Node* node);

private:
    map <Node *, Node *> nodeMap; //记录src节点与dest节点的映射关系
};