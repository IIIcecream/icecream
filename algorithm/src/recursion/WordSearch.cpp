#include "recursion/WordSearch.h"
#include <string>

// WordSearch LeetCode T79
bool WordSearch::solve()
{
    if (m_sWord.empty()) return true;
    for (int i = 0; i < (int)m_board.size(); ++i)
        for (int j = 0; j < (int)m_board[i].size(); ++j)
            if (m_sWord[0] == m_board[i][j])
                if (exist(m_board, m_sWord, i, j, 0)) return true;
    return false;
}

bool WordSearch::exist(vector<vector<char>>& board, string word, int i, int j, int pos)
{
    if (pos >= (int)word.length()) return true;
    if (i >= 0 && i < (int)m_board.size() && j >= 0 && j < (int)m_board[i].size())
    {
        board[i + 1][j] = ' ';
        if (exist(board, word, i - 1, j, pos + 1) ||
            exist(board, word, i + 1, j, pos + 1) ||
            exist(board, word, i, j - 1, pos + 1) ||
            exist(board, word, i, j + 1, pos + 1))
            return true;
        board[i + 1][j] = word[pos];
    }
    return false;
}

