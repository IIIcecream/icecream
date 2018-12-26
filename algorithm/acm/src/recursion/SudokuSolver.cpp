#include "recursion\SudokuSolver.h"

bool SudokuSolver::solve()
{
    solveSudoku(m_board);
    return true;
}

// Sudoku Solver LeetCode T37
bool SudokuSolver::solveSudoku(vector<vector<char>>& board)
{
    bool bValid = true;
    for(int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.')
            {
                bValid = false;
                for (int k = 0; k < 9; ++k)
                {
                    board[i][j] = (char)('0' + k);
                    if (valid(board, i, j))
                        if (solveSudoku(board)) return true;
                }
                // 1-9 都错了，说明前面有问题，回溯
                board[i][j] = '.';
                return false;
            }
        }
    
    return bValid;
}

bool SudokuSolver::valid(vector<vector<char>>& board, int i, int j)
{
    // 检查行
    for (int m = 0; m < 9; ++m)
    {
        if (m == j) continue;
        if (board[i][j] == board[i][m]) return false;
    }
    // 检查列
    for (int m = 0; m < 9; ++m)
    {
        if (m == i) continue;
        if (board[i][j] == board[m][j]) return false;
    }
    // 检查当前单元格
    for (int m = i / 3 * 3; m < i / 3 * 3 + 3; ++m)
    {
        for (int n = j / 3 * 3; n < j / 3 * 3 + 3; ++n)
        {
            if (m == i && n == j) continue;
            if (board[i][j] == board[m][n]) return false;
        }
    }
    return true;
}
