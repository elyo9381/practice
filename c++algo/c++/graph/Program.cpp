//Program.cpp
#include "Heuristic.h"
#include <stack>
using namespace std;

int main()
{
    Graph *graph = new Graph(9);//그래프 동적 생성

    graph->AddEdge(0, 1);//간선 추가
    graph->AddEdge(0, 2);//간선 추가
    graph->AddEdge(1, 2);//간선 추가
    graph->AddEdge(1, 3);//간선 추가
    graph->AddEdge(2, 4);//간선 추가
    graph->AddEdge(3, 6);//간선 추가
    graph->AddEdge(4, 5);//간선 추가
    graph->AddEdge(4, 6);//간선 추가
    graph->AddEdge(4, 7);//간선 추가
    graph->AddEdge(6, 8);//간선 추가

    graph->ViewNeighbors();    

    stack<Heuristic *> hs;    
    Heuristic *heu = new Heuristic(graph,0,7);//초기 경험 정보를 생성
    hs.push(heu);//스택에 보관

    while(hs.empty() == false) //반복(스택이 비어 있지 않다면)
    {
        heu = hs.top();//스택에서 경험 정보 꺼내옮
        hs.pop();
        heu->View();

        Heues nheues = heu->EnumNext();//스택에서 꺼내온 경험 정보에서 다음 경험 목록 조사
        HIter seek = nheues.begin();
        HIter last = nheues.end();
        for(  ;seek != last; ++seek)//반복(다음 경험 목록을 순차적으로 반복)
        {
            if((*seek)->IsGoal())//목적지에 도달하면
            {
                cout<<"솔루션 ";
                (*seek)->View();//결과 출력
                delete (*seek);
            }
            else//그렇지 않다면
            {
                hs.push(*seek);//스택에 보관
            }
        }
        delete heu;
    }
    return 0;
}
