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

	// Heuristic �������� stack�� �����ϴ� ������ �����Ѵ�. 
    stack<Heuristic *> hs;    
    // Heuristic�� �����Ҵ��Ͽ� ������ �׷����� Heuristic�� �����ͷ� ����Ų��. 
    Heuristic *heu = new Heuristic(graph,0,8);
    //heu�� ���ÿ� �ִ´� ������ �ϳ��� ����. 
    hs.push(heu);//���ÿ� ����

    while(hs.empty() == false) //�ݺ�(������ ��� ���� �ʴٸ�)
    {
    	//���ÿ��� top�� �����ϰ� 
        heu = hs.top();
        //top�� ������ 
        hs.pop();
        // heu�� foot(������ ���)�� �����ش�. 
        heu->View();

		//heu�� ���� �̿���带 ã�´�. �̿���带 ���ͷ� ��ȯ�Ѵ�. 
        Heues nheues = heu->EnumNext(); 
        // ��ȯ�� nheues���� heu�� �̿���尡 �����ϰ� �̰Ϳ��� ���������� 
		// Isgoal�̸� ����� ����ϰ� seek�� ����Ű�� �ش��带 �����Ѵ�. 
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
            else// �̿���忡�� goal�� ���ٸ�  
            {
            	//�̿���带 ���ÿ� �����Ѵ�. Ÿ���� nheues�� vector�̰� Heuristic �����̴�. 
                hs.push(*seek); 
            }
        }
        //�ش� ��带 �����ϰ� �������� �Ѿ��. 
        delete heu;
    }
    return 0;
}
