//Graph.h
#pragma once
#include "Edge.h"
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vertexs;
typedef Vertexs::iterator VIter;
typedef Vertexs::const_iterator CVIter;

typedef vector<Edge *> Edges;
typedef Edges::iterator EIter;
typedef Edges::const_iterator CEIter;

class Graph
{
    Vertexs vertexs;
    Edges edges;
public:    
    ~Graph(void);    
    bool AddVertex(int vt);
    bool Exist(int vt)const;
    bool AddEdge(int vt1, int vt2);//간선 추가
    bool Exist(int vt1,int vt2)const;
    void ViewNeighbors()const;
    void ViewNeighbor(int vt)const;
    Vertexs FindNeighbors(int vt);
};
