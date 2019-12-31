//Graph.h
#pragma once
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Neighbors;
class Graph
{
    const int vn;//정점의 개수
    int **matrix;//인접 행렬    
public:
    Graph(int vn);
    ~Graph(void);    
    void AddEdge(int start, int goal);//간선 추가
    void ViewNeighbors()const;
    void ViewNeighbor(int vt)const;
    Neighbors FindNeighbors(int vt);
};
