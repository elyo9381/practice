//Graph.cpp
#include "Graph.h"
#include <string.h>
Graph::Graph(int vn):vn(vn)
{
    matrix = new int *[vn];//매트릭스 메모리 할당
     for (int i = 0; i < vn; i++)
     {
         matrix[i] = new int[vn];//매트릭스 [i-row] 메모리 할당
         memset(matrix[i], 0, sizeof(int)*vn);//메모리 0으로 초기화
     }
}
Graph::~Graph(void)
{
    for (int i = 0; i < vn; i++)
    {
        delete[] matrix[i];//매트릭스 [i-row]  메모리 소멸
    }
    delete[] matrix;//매트릭스 메모리 해제
}
void Graph::AddEdge(int start, int goal)//간선 추가
{
    matrix[start][goal] = 1;//간선 설정
    //다음 코드를 주석 처리하면 방향성 있는 그래프
    matrix[goal][start] = 1;//간선 설정
}

void Graph::ViewNeighbors()const
{
    cout<<"=== 이웃 정점 ==="<<endl;
    for (int i = 0; i < vn; i++)
    {
        cout<<i<<"의 이웃: ";
        ViewNeighbor(i);//i정점의 이웃 보여주기
    }
    cout<<endl;
}

void Graph::ViewNeighbor(int vt)const
{
    for (int i = 0; i < vn; i++)
    {
        if(matrix[vt][i])
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

Neighbors Graph::FindNeighbors(int vt)
{
    Neighbors neighbors;
    for (int i = 0; i < vn; i++)
     {
         if(matrix[vt][i])
         {
             neighbors.push_back(i);
         }
     }
    return neighbors;
}
