#pragma once
#include "IACM.h"
#include <vector>

// ��������С·����
class Triangle : public IACM
{
public:
    Triangle(std::vector<std::vector<int>>& triangle) : m_triangle(triangle) {}
    virtual bool solve() override;

private:
    std::vector<std::vector<int>> m_triangle;
};