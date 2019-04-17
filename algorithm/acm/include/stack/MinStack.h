#pragma once
#include "IACM.h"
#include <stack>

using namespace std;

// ×îÐ¡Õ»
class MinStack : public IACM
{
public:
    MinStack() {}

    void push(int x);
    void pop();
    int top();
    int getMin();

    virtual bool solve() override { return true; }

private:
    stack<int> m_stack;
    stack<int> m_minStack;
};