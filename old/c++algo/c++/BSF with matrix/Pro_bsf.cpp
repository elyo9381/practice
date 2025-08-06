
#include "Heuristic.h"
#include <queue>
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
    
    queue<Heuristic *> hq;
    
    Heuristic *heu = new Heuristic(graph,0,8);//초기 경험 정보를 생성
    hq.push(heu);//큐에 보관
    while(hq.empty() == false) //반복(큐가 비어 있지 않다면)
    {
        heu = hq.front();//큐에서 경험 정보 꺼내옮
        hq.pop();
        //if(heu->IsGoal())//목적지에 도달하면
        //{
        //    cout<<"===== 솔루션 ";            
        //}
        //else
        //{
            cout<<"찾는중 ";
        //}
        heu->View();
        Heues nheues = heu->EnumNext();//큐에서 꺼내온 경험 정보에서 다음 경험 목록 조사
        HIter seek = nheues.begin();
        HIter last = nheues.end();
        for(  ;seek != last; ++seek)//반복(다음 경험 목록을 순차적으로 반복)
        {
            if((*seek)->IsGoal())//목적지에 도달하면
            {
                cout<<"===== 솔루션 ";            
                (*seek)->View();
                delete (*seek);
            }
            else
            {
                hq.push(*seek);//큐에 보관
            }
        }
        delete heu;
    }
    return 0;
}
