#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// ÉúÃüÓÎÏ·
class GameOfLife : public IACM
{
public:
    GameOfLife(vector<vector<int>> &board) : m_board(board) {}
    virtual bool solve() override;

private:
    void gameOfLife(vector<vector<int>>& board);
    bool needChange(int nCurState, int i, int j, vector<vector<int>>& board);
    int getValue(int i, int j, vector<vector<int>>& board);
private:
    vector<vector<int>> m_board;
};