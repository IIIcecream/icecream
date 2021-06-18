#pragma once

#include <vector>
using namespace std;

// 邻接矩阵表示无向图
struct Graph
{
    int vexnum = 0;           // 顶点数
    // int edgnum = 0;           // 边数
    //vector<int> vexs;     // 顶点集合
    vector<vector<int>> matrix; // 邻接矩阵
};