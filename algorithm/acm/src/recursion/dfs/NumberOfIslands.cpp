#include "recursion\dfs\NumberOfIslands.h"

bool NumberOfIslands::solve()
{
    return numIslands(m_grid);
}

// LeetCode 200 Number of Islands
int NumberOfIslands::numIslands(vector<vector<char>>& grid)
{
    int nRes = 0;
    if (grid.empty()) return nRes;
    nRow = grid.size();
    nCol = grid[0].size();

    for (int i = 0; i < nRow; ++i)
        for (int j = 0; j < nCol; ++j)
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                nRes++;
            }

    return nRes;
}

void NumberOfIslands::dfs(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= nRow || j >= nCol || grid[i][j] != '1') return;

    grid[i][j] = ' ';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

