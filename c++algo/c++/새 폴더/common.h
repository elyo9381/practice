//common.h
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;


class Member
{
    string name;
    int num;
public:
    Member(string name,int num)
    {
        this->name = name;
        this->num = num;
    }
    string GetName()const
    {
        return name;
    }
    int GetNum()const
    {
        return num;
    }
    void View()const
    {
        cout<<setw(10)<<setfill('0')<<num<<","<<name<<endl;
    }
};
 
int CompareByNum(Member *m1, Member *m2)
{
    int n1 = m1->GetNum();
    int n2 = m2->GetNum();
    return  n1 - n2;
}
 
 
int CompareByName(Member *m1, Member *m2)
{
    string n1 = m1->GetName();
    string n2 = m2->GetName();
    return  n1.compare(n2);
}
 
void MakeRandomMembers(Member **pbase, size_t n)
{
    for(size_t i=0; i<n; i++)
    {
        int num = rand()*rand();
        char buf[256];
        sprintf_s(buf, sizeof(buf),"name %010d",num);
        pbase[i] = new Member(buf,num);
    }
}
 
void RemoveMembers(Member **pbase, size_t n)
{
    for(size_t i=0; i<n; i++)
    {        
        delete pbase[i];
    }
}
 
void ViewMembers(Member **pbase, size_t n)
{
    for(size_t i=0;i<n; i++)
    {
        pbase[i]->View();
    }
}
