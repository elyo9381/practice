//App.h
#pragma once
#include "ehglobal.h"
#include "BinSearchTree.h"
class App
{
    BinSearchTree bstree;
public:    
    void Run();
private:
    int SelectMenu();
    void AddBook(); //���� �߰�
    void RemoveBook();//���� ����
    void FindBook()const; //���� �˻�    
    void ListAll()const; //��ü ����
};


