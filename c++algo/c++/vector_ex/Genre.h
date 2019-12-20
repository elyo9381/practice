//Genre.h
#pragma once
#include "ehglobal.h"
class Genre
{
    string name;
    const int num;
public:
    Genre(int num,string name);
    int GetNum()const;
    string GetName()const;
    void View()const;
};
