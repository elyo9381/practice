//Heuristic.cpp
#include "Heuristic.h"
#include <algorithm>

Heuristic::Heuristic(Graph *graph,int start,int goal)
{
    this->graph = graph;
    foots.push_back(start);
    this->goal = goal;
}




Heues Heuristic::EnumNext()
{
    Heues nheues;
    int last_foot = (*foots.rbegin());//���� �ֱٿ� �湮�� ����
    Vertexs neighbors = graph->FindNeighbors(last_foot);//������ �湮 ������ �̿��ϴ� ������ ����
    FIter seek = neighbors.begin();
    FIter last = neighbors.end();
    for(  ;seek != last; ++seek)
    {
        if(find(foots.begin(), foots.end(),*seek) == foots.end())//�湮�� ���� ������
        {
            nheues.push_back(new Heuristic(this,*seek));//*seek�� �߰� �湮�ϴ� ���ο� ������ ����
        }            
    }
    return nheues;
}

bool Heuristic::IsGoal()const
{
    return (*foots.rbegin()) == goal;
}

void Heuristic::View()const
{
    cout<<"Foots: ";
    CFIter seek = foots.begin();
    CFIter last = foots.end();
    for(  ;seek != last; ++seek)
    {
        cout<<(*seek)<<" ";
    }
    cout<<endl;
}

Heuristic::Heuristic(const Heuristic *bheu,int vt)
{
    this->graph = bheu->graph;
    foots = bheu->foots;
    this->goal = bheu->goal;

    foots.push_back(vt);//vt�� �湮�� ������ �߰�
}
