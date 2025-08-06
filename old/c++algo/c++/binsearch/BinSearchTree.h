//BinSearchTree.h
#pragma once
#include "Book.h"
struct Node
{
    Book *book;
    Node *left;
    Node *right;
    Node *parent;
    Node(Book *book)
    {
        this->book = book;
        left = right = parent = 0;
    }    
};    

class BinSearchTree
{    
    Node *root;
public:
    BinSearchTree(void);
    ~BinSearchTree(void);
    bool AddBook(int bnum,string title);
    bool FindBook(int bnum)const;
    bool RemoveBook(int bnum);
    void ListAll()const;    
private:
    Node *Find(Node *sr, int bnum)const;
    void HangNode(Node *parent, Node *now);
    void DeHang(Node *now);
    void PreOrder(Node *sr)const;    
    void InOrder(Node *sr)const;    
    void PostOrder(Node *sr)const;
    void Clear(Node *sr);
};

