//Program.cpp
#include "Heuristic.h"
#include <stack>
using namespace std;

int main()
{
    stack<Heuristic *> hs;

    Bucket bucket;
    for(int i = 0; i<3;i++)
    {
        bucket.push_back(i);
	}

    
    Heuristic *heu = new Heuristic(bucket);//hs.push(0~9���� ���� ������ �ʱ� ���� ������ ����
    hs.push(heu);//���ÿ� ����
    while(hs.empty() == false) //�ݺ�(������ ��� ���� �ʴٸ�)
    {
    	cout<<"test"<<endl;
        heu = hs.top();//���ÿ��� ���� ���� ������
//        cout<<hs.top()<<endl;
		hs.pop();
		
        Heues nheues = heu->EnumNext();//���ÿ��� ������ ���� �������� ���� ���� ��� ����
        HIter seek = nheues.begin();
        HIter last = nheues.end();
        for(  ;seek != last; ++seek)//�ݺ�(���� ���� ����� ���������� �ݺ�)
        {
            if((*seek)->IsEmpty())//�ٱ��Ͽ� ���� ���
            {
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
