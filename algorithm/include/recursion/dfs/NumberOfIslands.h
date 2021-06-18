#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// µºÓìµÄ¸öÊý
class NumberOfIslands : public IACM
{
public:
    NumberOfIslands(vector<vector<char>>& grid) : m_grid(grid) {}
    virtual bool solve() override;

private:
    int numIslands(vector<vector<char>>& grid);
    void dfs(vector<vector<char>> &grid, int i, int j);

private:
    vector<vector<char>> m_grid;
    int nRow, nCol;
};