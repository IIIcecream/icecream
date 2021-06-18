#include "stack/MinStack.h"
#include "ACMMathCommon.h"

// LeetCode 155 ×îÐ¡Õ»
void MinStack::push(int x)
{
    m_stack.push(x);
    int nMin = x;
    if (m_minStack.empty()) m_minStack.push(x);
    else m_minStack.push(ACM::min(x, m_minStack.top()));
}

void MinStack::pop()
{
    m_stack.pop();
    m_minStack.pop();
}

int MinStack::top()
{
    return m_stack.top();
}

int MinStack::getMin()
{
    return m_minStack.top();
}
