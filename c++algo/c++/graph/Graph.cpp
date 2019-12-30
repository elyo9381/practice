//Graph.cpp
#include "Graph.h"
#include <string.h>
Graph::Graph(int vn):vn(vn)
{
    matrix = new int *[vn];//��Ʈ���� �޸� �Ҵ�
     for (int i = 0; i < vn; i++)
     {
         matrix[i] = new int[vn];//��Ʈ���� [i-row] �޸� �Ҵ�
         memset(matrix[i], 0, sizeof(int)*vn);//�޸� 0���� �ʱ�ȭ
     }
}
Graph::~Graph(void)
{
    for (int i = 0; i < vn; i++)
    {
        delete[] matrix[i];//��Ʈ���� [i-row]  �޸� �Ҹ�
    }
    delete[] matrix;//��Ʈ���� �޸� ����
}
void Graph::AddEdge(int start, int goal)//���� �߰�
{
    matrix[start][goal] = 1;//���� ����
    //���� �ڵ带 �ּ� ó���ϸ� ���⼺ �ִ� �׷���
    matrix[goal][start] = 1;//���� ����
}

void Graph::ViewNeighbors()const
{
    cout<<"=== �̿� ���� ==="<<endl;
    for (int i = 0; i < vn; i++)
    {
        cout<<i<<"�� �̿�: ";
        ViewNeighbor(i);//i������ �̿� �����ֱ�
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
