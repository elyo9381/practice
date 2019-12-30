//Heuristic.h
#pragma once
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Bucket;
typedef Bucket::iterator BIter;
typedef Bucket::const_iterator CBIter;

class Heuristic;
typedef vector<Heuristic *> Heues;
typedef Heues::iterator HIter;
typedef Heues::const_iterator CHIter;

class Heuristic
{
    Bucket original;
    Bucket out;
public:
    Heuristic(Bucket bucket);
    Heues EnumNext();
    void View()const;
    bool IsEmpty()const;
private:
    Heuristic(const Heuristic *bheu,int ball);
};
