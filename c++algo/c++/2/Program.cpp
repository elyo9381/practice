//Program.cpp
#include "Heuristic.h"
#include <stack>
using namespace std;

int main()
{
    stack<Heuristic *> hs;

    Bucket bucket;
    Bucket bucket1;
    for(int i = 0; i<3;i++)
    {
        bucket.push_back(i);
	}
//	for(int i = 0; i<3;i++)
//    {
//        bucket1.push_back(i);
//	}
//
//    Heuristic *heu1 = new Heuristic(bucket1);//hs.push(0~9���� ���� ������ �ʱ� ���� ������ ����
//    hs.push(heu1);//���ÿ� ����
    
    Heuristic *heu = new Heuristic(bucket);//hs.push(0~9���� ���� ������ �ʱ� ���� ������ ����
    hs.push(heu);//���ÿ� ����

	cout<<"size "<<hs.size()<<endl;
	
	
	    
    while(hs.empty() == false) //�ݺ�(������ ��� ���� �ʴٸ�)
    {
    	cout<<"test"<<endl;
        heu = hs.top();//���ÿ��� ���� ���� ������
//        cout<<hs.top()<<endl;

		cout<<"pop!!"<<endl;
		hs.pop();
		
        Heues nheues = heu->EnumNext();//���ÿ��� ������ ���� �������� ���� ���� ��� ����
        HIter seek = nheues.begin();
        HIter last = nheues.end();
        for(  ;seek != last; ++seek)//�ݺ�(���� ���� ����� ���������� �ݺ�)
        {
            if((*seek)->IsEmpty())//�ٱ��Ͽ� ���� ���
            {
            	cout<<"IsEmpty!!"<<endl;
                (*seek)->View();//��� ���
                delete (*seek);
            }
            else//�׷��� �ʴٸ�
            {
            	cout<<"else push !!"<<endl;
                hs.push(*seek);//���ÿ� ����
            }
        }
        delete heu;
    }
    return 0;
}
