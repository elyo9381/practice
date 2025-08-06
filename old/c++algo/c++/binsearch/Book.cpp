//Book.cpp
#include "Book.h"

Book::Book(int bnum,string title):bnum(bnum)
{
    this->title = title;
}
int Book::GetBNum()const
{
    return bnum;
}
string Book::GetTitle()const
{
    return title;
}
void Book::View()const
{
    cout<<bnum<<", "<<title<<endl;
}
