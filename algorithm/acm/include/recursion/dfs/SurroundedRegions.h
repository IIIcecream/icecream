#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// ��Χ�Ƶ�����
class SurroundedRegions : public IACM
{
public:
    SurroundedRegions(vector<vector<char>>& board) : m_board(board) {}
    virtual bool solve() override;

private:
    void solve(vector<vector<char>>& board);

private:
    vector<vector<char>> m_board;
};