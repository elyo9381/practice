//Book.h
#pragma once
#include "ehglobal.h"
class Book
{    
    const int bnum;
    string title;
public:
    Book(int bnum,string title);    
    int GetBNum()const;
    string GetTitle()const;
    void View()const;
};

