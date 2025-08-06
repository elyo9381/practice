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
    void AddBook(); //도서 추가
    void RemoveBook();//도서 삭제
    void FindBook()const; //도서 검색    
    void ListAll()const; //전체 보기
};


