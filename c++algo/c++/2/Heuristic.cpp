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
        //하나의 공을 꺼낸 경험 정보를 생성하여 보관
    
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
    return original.empty(); //바구니가 비었는지 판별
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
        if((*seek)==ball) //seek위치의 공과 ball이 같으면
        {
            original.erase(seek);//공을 꺼냄
            out.push_back(ball);//꺼낸 바구니에 보관
						
            break;
        }        
    }
}
