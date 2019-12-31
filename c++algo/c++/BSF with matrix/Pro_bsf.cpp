
#include "Heuristic.h"
#include <queue>
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
    
    queue<Heuristic *> hq;
    
    Heuristic *heu = new Heuristic(graph,0,8);//�ʱ� ���� ������ ����
    hq.push(heu);//ť�� ����
    while(hq.empty() == false) //�ݺ�(ť�� ��� ���� �ʴٸ�)
    {
        heu = hq.front();//ť���� ���� ���� ������
        hq.pop();
        //if(heu->IsGoal())//�������� �����ϸ�
        //{
        //    cout<<"===== �ַ�� ";            
        //}
        //else
        //{
            cout<<"ã���� ";
        //}
        heu->View();
        Heues nheues = heu->EnumNext();//ť���� ������ ���� �������� ���� ���� ��� ����
        HIter seek = nheues.begin();
        HIter last = nheues.end();
        for(  ;seek != last; ++seek)//�ݺ�(���� ���� ����� ���������� �ݺ�)
        {
            if((*seek)->IsGoal())//�������� �����ϸ�
            {
                cout<<"===== �ַ�� ";            
                (*seek)->View();
                delete (*seek);
            }
            else
            {
                hq.push(*seek);//ť�� ����
            }
        }
        delete heu;
    }
    return 0;
}
