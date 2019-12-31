//Edge.h
#pragma once
class Edge
{
    int vt1;
    int vt2;
public:
    Edge(int vt1,int vt2);
    bool Exist(int vt)const;
    bool Exist(int vt1, int vt2)const;
    int Other(int vt)const;
    void View()const;
};
