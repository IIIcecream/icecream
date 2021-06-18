
#include <iostream>
#include "others/GasStation.h"

bool GasStation::solve()
{
    vector<int> gas;
    gas.push_back(1);
    gas.push_back(1);
    gas.push_back(1);
    gas.push_back(1);
    gas.push_back(3);
    vector<int> cost;
    cost.push_back(1);
    cost.push_back(2);
    cost.push_back(1);
    cost.push_back(2);
    cost.push_back(1);

    cout << canCompleteCircuit(gas, cost);

    return true;
}

int GasStation::canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int res = 0, nSum = 0, nAllSum = 0;
    for (int i = 0; i < (int)gas.size(); ++i)
    {
        nSum += gas[i] - cost[i];
        nAllSum += gas[i] - cost[i];
        if (nSum < 0) res = i + 1, nSum = 0;
    }

    return nAllSum < 0 ? -1 : res;
}

GasStation::RandomListNode *GasStation::copyRandomList(RandomListNode *head)
{
    if (!head) return nullptr;

    vector<int> nextCache;
    RandomListNode *pOld = head, *pTempHead = head, *pLast = nullptr, *pRes = nullptr;

    while (pOld)
    {
        RandomListNode *pNode = new RandomListNode(pOld->label);
        if (!pRes) pRes = pNode;
        if (pLast) pLast->next = pNode;
        pLast = pNode;

        // 判断随机指针是否为空
        if (!pOld->random) pNode->random = nullptr;
        else
        {
            // 判断随机指针是否指向前面
            bool bPrev = false;
            while (pOld != head)
            {

            }
        }

        pOld = pOld->next;
    }
    return pRes;
}

