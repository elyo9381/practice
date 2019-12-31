//Graph.cpp
#include "Graph.h"
#include <string.h>
#include <algorithm>

Graph::~Graph(void)
{
    EIter seek = edges.begin();
    EIter last = edges.end();
    for(  ;seek != last; ++seek)
    {
        delete (*seek);//���� �Ҹ�        
    }    
}
bool Graph::AddVertex(int vt)
{
    if(Exist(vt))
    {
        return false;
    }
    vertexs.push_back(vt);
    return true;
}

bool Graph::Exist(int vt)const
{
    return find(vertexs.begin(),vertexs.end(),vt) != vertexs.end();
}

bool Graph::AddEdge(int vt1, int vt2)//���� �߰�
{
    if(Exist(vt1)&&Exist(vt2))
    {
        if(Exist(vt1,vt2))
        {
            return false;
        }
        edges.push_back(new Edge(vt1,vt2));
        return true;
    }
    return false;
}

bool Graph::Exist(int vt1,int vt2)const
{
    CEIter seek = edges.begin();
    CEIter last = edges.end();
    for(  ;seek != last; ++seek)
    {
        if((*seek)->Exist(vt1,vt2))
        {
            return true;
        }
    }    
    return false;
}

void Graph::ViewNeighbors()const
{
    cout<<"=== �̿� ���� ==="<<endl;
    CVIter seek = vertexs.begin();
    CVIter last = vertexs.end();
    for(   ;seek != last; ++seek)
    {
        cout<<(*seek)<<"�� �̿�: ";
        ViewNeighbor(*seek);//i������ �̿� �����ֱ�
    }
    cout<<endl;
}

void Graph::ViewNeighbor(int vt)const
{
    CEIter seek = edges.begin();
    CEIter last = edges.end();
    for(  ;seek != last; ++seek)
    {
        if((*seek)->Exist(vt))
        {
            cout<<(*seek)->Other(vt)<<" ";
        }
    }
    cout<<endl;
}

Vertexs Graph::FindNeighbors(int vt)
{
    Vertexs neighbors;
    EIter seek = edges.begin();
    EIter last = edges.end();

    for(  ;seek != last; ++seek)
    {
        if((*seek)->Exist(vt))
        {
            neighbors.push_back((*seek)->Other(vt));
        }
    }    
    return neighbors;
}
