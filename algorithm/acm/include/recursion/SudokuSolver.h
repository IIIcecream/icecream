#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// ½âÊý¶À
class SudokuSolver : public IACM
{
public:
    SudokuSolver(vector<vector<char>>& board) : m_board(board) {}
    virtual bool solve() override;

private:
    bool solveSudoku(vector<vector<char>>& board);
    bool valid(vector<vector<char>>& board, int i, int j);
private:
    vector<vector<char>> m_board;
};