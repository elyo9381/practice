//Heuristic.cpp
#include "Heuristic.h"
#include <algorithm>


// ó�� start�� goal�� graph�� �Է¹޴´�. 
Heuristic::Heuristic(Graph *graph,int start,int goal)
{
    this->graph = graph;
    foots.push_back(start);//foots�� �湮�� ��带 �����ϴ°��̴�. 
    this->goal = goal;
}



Heues Heuristic::EnumNext()
{
	//heu->EnuNext()�� �ϰ� �Ǹ� 
	// foots�� vector�� ���ݺ��ڸ� ���ؼ� �ֱٿ� �湮�� ������ ���Ѵ�. 
    Heues nheues;
    int last_foot = (*foots.rbegin());//���� �ֱٿ� �湮�� ����
    Neighbors neighbors = graph->FindNeighbors(last_foot);//������ �湮 ������ �̿��ϴ� ������ ����
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
    	// ������ �湮������ �̿����� foots�� �����Ѱ� �ִ��� ã�´�. 
        if(find(foots.begin(), foots.end(),*seek) == foots.end())//�湮�� ���� ������
        {
        	//�̿��ϴ� ��带 �湮�ϴ� �޼ҵ� 
        	// this�� �޾ƿ´�. ���� Ŭ�������� 
        	//*seek�� �߰� �湮�� Ŭ������  
            nheues.push_back(new Heuristic(this,*seek));//*seek�� �߰� �湮�ϴ� ���ο� ������ ����
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


// �̿��ϴ� ��带 �湮�ϴ� �޼ҵ� 
Heuristic::Heuristic(const Heuristic *bheu,int vt)
{
	//this�� ���ؼ� ���� ���� Ŭ������ ������ ������ 
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
    foots.push_back(vt);//vt�� �湮�� ������ �߰�
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
