#include "others/GameOfLife.h"

bool GameOfLife::solve()
{
    gameOfLife(m_board);
    return true;
}

// LeetCode 289. Game of Life
void GameOfLife::gameOfLife(vector<vector<int>>& board)
{
    for (size_t i = 0; i < board.size(); ++i)
    {
        for (size_t j = 0; j < board[0].size(); ++j)
        {
            if (needChange(board[i][j], i, j, board))
            {
                // 如果需要转换状态，0先变成-1, 1先变成2。最后再统一修改状态
                board[i][j] = board[i][j] == 0 ? -1 : 2;
            }
        }
    }

    // 修改状态
    for (size_t i = 0; i < board.size(); ++i)
        for (size_t j = 0; j < board[0].size(); ++j)
            if (board[i][j] == -1) board[i][j] = 1;
            else if (board[i][j] == 2) board[i][j] = 0;
}

/*!
*@brief        是否需要修改状态
*@author       tangw  2019/08/01  19:54
*/
bool GameOfLife::needChange(int nCurState, int i, int j, vector<vector<int>>& board)
{
    int nAliveAround = 0;

    if (getValue(i - 1, j, board)) nAliveAround++;
    if (getValue(i - 1, j - 1, board)) nAliveAround++;
    if (getValue(i - 1, j + 1, board)) nAliveAround++;
    if (getValue(i, j + 1, board)) nAliveAround++;
    if (getValue(i, j - 1, board)) nAliveAround++;
    if (getValue(i + 1, j, board)) nAliveAround++;
    if (getValue(i + 1, j + 1, board)) nAliveAround++;
    if (getValue(i + 1, j - 1, board)) nAliveAround++;

    if (!board[i][j] && nAliveAround == 3 ) return true;
    if (board[i][j])
    {
        if (nAliveAround == 2 || nAliveAround == 3) return false;
        return true;
    }
    return false;
}

/*!
*@brief        获取某位置的状态
*@author       tangw  2019/08/01  19:54
*/
int GameOfLife::getValue(int i, int j, vector<vector<int>>& board)
{
    if (i < 0 || i >= board.size()) return 0;
    if (j < 0 || j >= board[0].size()) return 0;
    if (board[i][j] == -1 || board[i][j] == 0) return 0;
    return 1;
}
