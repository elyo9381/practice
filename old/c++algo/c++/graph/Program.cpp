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

	// Heuristic 형식으로 stack을 구성하는 변수를 지정한다. 
    stack<Heuristic *> hs;    
    // Heuristic을 동적할당하여 구성된 그래프를 Heuristic의 포인터로 가르킨다. 
    Heuristic *heu = new Heuristic(graph,0,8);
    //heu를 스택에 넣는다 스택은 하나만 들어간다. 
    hs.push(heu);//스택에 보관

    while(hs.empty() == false) //반복(스택이 비어 있지 않다면)
    {
    	//스택에서 top를 지정하고 
        heu = hs.top();
        //top를 꺼낸다 
        hs.pop();
        // heu의 foot(접근한 노드)를 보여준다. 
        heu->View();

		//heu의 다음 이웃노드를 찾는다. 이웃노드를 벡터로 반환한다. 
        Heues nheues = heu->EnumNext(); 
        // 반환된 nheues에는 heu의 이웃노드가 존재하고 이것에서 순차적으로 
		// Isgoal이면 결과를 출력하고 seek가 가르키는 해당노드를 해제한다. 
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
            else// 이웃노드에서 goal이 없다면  
            {
            	//이웃노드를 스택에 보관한다. 타입은 nheues는 vector이고 Heuristic 형식이다. 
                hs.push(*seek); 
            }
        }
        //해당 노드를 해제하고 다음노드로 넘어간다. 
        delete heu;
    }
    return 0;
}
