//Edge.cpp
#include "Edge.h"
#include <iostream>
using namespace std;

Edge::Edge(int vt1,int vt2)
{
    this->vt1 = vt1;
    this->vt2 = vt2;
}

bool Edge::Exist(int vt)const
{
    return (vt1 == vt)||(vt2==vt);
    //return (vt1 == vt);// ���⼺ �ִ� �׷��� 
}

bool Edge::Exist(int vt1, int vt2)const
{
    return Exist(vt1) && Exist(vt2);
}

int Edge::Other(int vt)const
{
    if(vt1 == vt)
    {
        return vt2;
    }

	//�ּ� ó���ϸ� ���⼺ �ִ� �׷���  
    if(vt2 == vt)
    {
        return vt1;
    } 

    return -1;
}

void Edge::View()const
{
    cout<<"("<<vt1<<","<<vt2<<")";
}
