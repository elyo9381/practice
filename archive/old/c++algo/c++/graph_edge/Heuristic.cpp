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
    int last_foot = (*foots.rbegin());//가장 최근에 방문한 정점
    Vertexs neighbors = graph->FindNeighbors(last_foot);//마지막 방문 정점의 이웃하는 정점을 구함
    FIter seek = neighbors.begin();
    FIter last = neighbors.end();
    for(  ;seek != last; ++seek)
    {
        if(find(foots.begin(), foots.end(),*seek) == foots.end())//방문한 적이 없으면
        {
            nheues.push_back(new Heuristic(this,*seek));//*seek를 추가 방문하는 새로운 경험을 생성
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

    foots.push_back(vt);//vt를 방문한 행적에 추가
}
