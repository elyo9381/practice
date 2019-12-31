//Heuristic.cpp
#include "Heuristic.h"
#include <algorithm>


// 처음 start와 goal을 graph를 입력받는다. 
Heuristic::Heuristic(Graph *graph,int start,int goal)
{
    this->graph = graph;
    foots.push_back(start);//foots는 방문한 노드를 보관하는곳이다. 
    this->goal = goal;
}



Heues Heuristic::EnumNext()
{
	//heu->EnuNext()를 하게 되면 
	// foots의 vector의 역반복자를 통해서 최근에 방문한 정점을 구한다. 
    Heues nheues;
    int last_foot = (*foots.rbegin());//가장 최근에 방문한 정점
    Neighbors neighbors = graph->FindNeighbors(last_foot);//마지막 방문 정점의 이웃하는 정점을 구함
    FIter seek = neighbors.begin();
    FIter last = neighbors.end();
    for(  ;seek != last; ++seek)
    {
//    		cout<<"enumNext in verifing foots "<<endl;
//			CFIter s = foots.begin();
//			CFIter l = foots.end();
//			for(  ;s != l; ++s)
//			{
//			    cout<<(*s)<<" ";
//			}
//			cout<<endl;
//			cout<<"enumNext in "<<endl;
//			cout<<*foots.begin()<<endl;
//			cout<<*foots.end()<<endl;
//			cout<<*seek<<endl;
    	// 마지막 방문정점의 이웃에서 foots와 동일한게 있는지 찾는다. 
        if(find(foots.begin(), foots.end(),*seek) == foots.end())//방문한 적이 없으면
        {
        	//이웃하는 노드를 방문하는 메소드 
        	// this를 받아온다. 현재 클래스정보 
        	//*seek를 추가 방문한 클래스를  
            nheues.push_back(new Heuristic(this,*seek));//*seek를 추가 방문하는 새로운 경험을 생성
        }            
    }
    return nheues;
}

bool Heuristic::IsGoal()const
{
    return (*foots.rbegin()) == goal;
}

void Heuristic::View()const
{
    cout<<"Foots: ";
    CFIter seek = foots.begin();
    CFIter last = foots.end();
    for(  ;seek != last; ++seek)
    {
        cout<<(*seek)<<" ";
    }
    cout<<endl;
}


// 이웃하는 노드를 방문하는 메소드 
Heuristic::Heuristic(const Heuristic *bheu,int vt)
{
	//this를 통해서 받은 현재 클래스의 정보를 가지고 
    this->graph = bheu->graph;
    foots = bheu->foots;
    this->goal = bheu->goal;
    
//    cout<<"Heuristic in verifing foots "<<endl;
//			CFIter s = foots.begin();
//			CFIter l = foots.end();
//			for(  ;s != l; ++s)
//			{
//			    cout<<(*s)<<" ";
//			}
//	cout<<endl;
//
    foots.push_back(vt);//vt를 방문한 행적에 추가
//    
//    cout<<"Heuristic in push after verifing foots "<<endl;
//			CFIter s1 = foots.begin();
//			CFIter l1 = foots.end();
//			for(  ;s1 != l1; ++s1)
//			{
//			    cout<<(*s1)<<" ";
//			}
//    cout<<endl;
}
