#pragma once
#include "IACM.h"
#include <vector>

// 三角形最小路径和
class Triangle : public IACM
{
public:
    Triangle(std::vector<std::vector<int>>& triangle) : m_triangle(triangle) {}
    virtual bool solve() override;

private:
    std::vector<std::vector<int>> m_triangle;
};