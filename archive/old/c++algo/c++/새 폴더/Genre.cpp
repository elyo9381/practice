//Genre.cpp
#include "Genre.h"
 
Genre::Genre(int num,string name):num(num)
{
    this->name = name;
}
int Genre::GetNum()const
{
    return num;
}
string Genre::GetName()const
{
    return name;
}
void Genre::View()const
{
    cout<<"장르 No."<<num<<" 장르명:"<<name<<endl;
}
