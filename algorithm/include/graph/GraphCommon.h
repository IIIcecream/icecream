#pragma once

#include <vector>
using namespace std;

// �ڽӾ����ʾ����ͼ
struct Graph
{
    int vexnum = 0;           // ������
    // int edgnum = 0;           // ����
    //vector<int> vexs;     // ���㼯��
    vector<vector<int>> matrix; // �ڽӾ���
};