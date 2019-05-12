#include "recursion\dfs\SurroundedRegions.h"

bool SurroundedRegions::solve()
{
    solve(m_board);
    return true;
}

// Leetcode 130 Surrounded Regions
// dfs，四周的'O'开始做dfs，标记上dfs的区域为'A'，全完成之后，除A以外的区域都标记为'X'，然后再将'A'->'O'
void SurroundedRegions::solve(vector<vector<char>>& board)
{
    if (board.empty()) return;
    nRow = board.size();
    nCol = board[0].size();

    for (int i = 0; i < nRow; ++i)
    {
        dfs(board, i, 0);
        dfs(board, i, nCol - 1);
    }
    for (int j = 0; j < nCol; ++j)
    {
        dfs(board, 0, j);
        dfs(board, nRow - 1, j);
    }

    for (size_t i = 0; i < board.size(); ++i)
    {
        for (size_t j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == 'A') board[i][j] = 'O';
        }
    }
}

void SurroundedRegions::dfs(vector<vector<char>> &board, int i, int j)
{
    if (i < 0 || j < 0 || i >= nRow || j >= nCol || board[i][j] != 'O') return;

    board[i][j] = 'A';
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
}

