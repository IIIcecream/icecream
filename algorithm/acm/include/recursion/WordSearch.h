#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// µ¥´ÊËÑË÷
class WordSearch : public IACM
{
public:
    WordSearch(vector<vector<char>>& board, string word) : m_board(board), m_sWord(word) {}
    virtual bool solve() override;

private:
    bool exist(vector<vector<char>>& board, string word, int i, int j, int pos);

private:
    vector<vector<char>> m_board;
    string m_sWord;
};