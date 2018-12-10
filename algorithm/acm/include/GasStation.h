#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

class GasStation : public IACM
{
public:
    virtual bool solve() override;

    struct RandomListNode {
        int label;
        RandomListNode *next, *random;
        RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
    };

private:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

    RandomListNode *copyRandomList(RandomListNode *head);
};
