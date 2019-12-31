//Graph.h
#pragma once
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Neighbors;
class Graph
{
    const int vn;//������ ����
    int **matrix;//���� ���    
public:
    Graph(int vn);
    ~Graph(void);    
    void AddEdge(int start, int goal);//���� �߰�
    void ViewNeighbors()const;
    void ViewNeighbor(int vt)const;
    Neighbors FindNeighbors(int vt);
};
