//Program.cpp
#include "Heuristic.h"
#include <stack>
using namespace std;

int main()
{
    Graph *graph = new Graph(9);//�׷��� ���� ����

    graph->AddEdge(0, 1);//���� �߰�
    graph->AddEdge(0, 2);//���� �߰�
    graph->AddEdge(1, 2);//���� �߰�
    graph->AddEdge(1, 3);//���� �߰�
    graph->AddEdge(2, 4);//���� �߰�
    graph->AddEdge(3, 6);//���� �߰�
    graph->AddEdge(4, 5);//���� �߰�
    graph->AddEdge(4, 6);//���� �߰�
    graph->AddEdge(4, 7);//���� �߰�
    graph->AddEdge(6, 8);//���� �߰�

    graph->ViewNeighbors();    

    stack<Heuristic *> hs;    
    Heuristic *heu = new Heuristic(graph,0,7);//�ʱ� ���� ������ ����
    hs.push(heu);//���ÿ� ����

    while(hs.empty() == false) //�ݺ�(������ ��� ���� �ʴٸ�)
    {
        heu = hs.top();//���ÿ��� ���� ���� ������
        hs.pop();
        heu->View();

        Heues nheues = heu->EnumNext();//���ÿ��� ������ ���� �������� ���� ���� ��� ����
        HIter seek = nheues.begin();
        HIter last = nheues.end();
        for(  ;seek != last; ++seek)//�ݺ�(���� ���� ����� ���������� �ݺ�)
        {
            if((*seek)->IsGoal())//�������� �����ϸ�
            {
                cout<<"�ַ�� ";
                (*seek)->View();//��� ���
                delete (*seek);
            }
            else//�׷��� �ʴٸ�
            {
                hs.push(*seek);//���ÿ� ����
            }
        }
        delete heu;
    }
    return 0;
}
