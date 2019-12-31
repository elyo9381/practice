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
//    Heuristic *heu1 = new Heuristic(bucket1);//hs.push(0~9까지 공을 보관한 초기 경험 정보를 생성
//    hs.push(heu1);//스택에 보관
    
    Heuristic *heu = new Heuristic(bucket);//hs.push(0~9까지 공을 보관한 초기 경험 정보를 생성
    hs.push(heu);//스택에 보관

	cout<<"size "<<hs.size()<<endl;
	
	
	    
    while(hs.empty() == false) //반복(스택이 비어 있지 않다면)
    {
    	cout<<"test"<<endl;
        heu = hs.top();//스택에서 경험 정보 꺼내옮
//        cout<<hs.top()<<endl;

		cout<<"pop!!"<<endl;
		hs.pop();
		
        Heues nheues = heu->EnumNext();//스택에서 꺼내온 경험 정보에서 다음 경험 목록 조사
        HIter seek = nheues.begin();
        HIter last = nheues.end();
        for(  ;seek != last; ++seek)//반복(다음 경험 목록을 순차적으로 반복)
        {
            if((*seek)->IsEmpty())//바구니에 공이 비면
            {
            	cout<<"IsEmpty!!"<<endl;
                (*seek)->View();//결과 출력
                delete (*seek);
            }
            else//그렇지 않다면
            {
            	cout<<"else push !!"<<endl;
                hs.push(*seek);//스택에 보관
            }
        }
        delete heu;
    }
    return 0;
}
