//Heuristic.cpp
#include "Heuristic.h"

Heuristic::Heuristic(Bucket bucket)
{
    original = bucket;
    
    for(int i = 0; i<3;i++)
    {
        cout<<original[i]<<" ";
	}

}
Heues Heuristic::EnumNext()
{
	
	cout<<"EnumNext"<<endl;
	Heues heues;
    BIter seek = original.begin();
    BIter last = original.end();
    for(  ;seek != last ; ++seek)
    {
        //�ϳ��� ���� ���� ���� ������ �����Ͽ� ����
    
        heues.push_back(new Heuristic(this,*seek)); 
    }
    return heues;
}

void Heuristic::View()const
{
    CBIter seek = out.begin();
    CBIter last = out.end();
    for(  ;seek != last ; ++seek)
    {
        cout<<(*seek)<<" ";
    }
    cout<<endl;
}

bool Heuristic::IsEmpty()const
{
    return original.empty(); //�ٱ��ϰ� ������� �Ǻ�
}

Heuristic::Heuristic(const Heuristic *bheu,int ball)
{
    out = bheu->out;
    original = bheu->original;
    BIter seek = original.begin();
    BIter last = original.end();
	
	
	cout<<"Heuristic"<<endl;
	cout<<ball<<endl;
    for(  ;seek != last; ++seek)
    {
        if((*seek)==ball) //seek��ġ�� ���� ball�� ������
        {
            original.erase(seek);//���� ����
            out.push_back(ball);//���� �ٱ��Ͽ� ����
						
            break;
        }        
    }
}
