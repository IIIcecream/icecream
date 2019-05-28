#pragma once

#include <vector>
#include <map>
#include "IACM.h"
using namespace std;

// ͼ�ڵ�
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

// ��¡ͼ
class CloneGraph : public IACM
{
public:
    virtual bool solve() override;

    Node * cloneGraph(Node* node);

private:
    map <Node *, Node *> nodeMap; //��¼src�ڵ���dest�ڵ��ӳ���ϵ
};