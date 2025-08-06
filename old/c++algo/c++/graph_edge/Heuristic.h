//Heuristic.h
#pragma once
#include "Graph.h"
#include <vector>
using namespace std;

typedef vector<int> Foots;
typedef Foots::iterator FIter;
typedef Foots::const_iterator CFIter;

class Heuristic;
typedef vector<Heuristic *> Heues;
typedef Heues::iterator HIter;
typedef Heues::const_iterator CHIter;

class Heuristic
{
    Graph *graph;    
    int goal;
    Foots foots;
public:
    Heuristic(Graph *graph, int start,int goal);    
    Heues EnumNext();
    bool IsGoal()const;
    void View()const;    
private:
    Heuristic(const Heuristic *bheu,int vt);
};
