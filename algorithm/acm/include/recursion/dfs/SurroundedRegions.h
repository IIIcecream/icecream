#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// ±»Î§ÈÆµÄÇøÓò
class SurroundedRegions : public IACM
{
public:
    SurroundedRegions(vector<vector<char>>& board) : m_board(board) {}
    virtual bool solve() override;

private:
    void solve(vector<vector<char>>& board);
    void dfs(vector<vector<char>> &board, int i, int j);

private:
    vector<vector<char>> m_board;
    int nRow, nCol;
};