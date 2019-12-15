//App.h
#pragma once
#include "Genre.h"
#include "ehglobal.h"
#include <vector>
#include <algorithm>
using std::vector;
using std::find;
using std::find_if;
typedef vector<Genre *> Genres;
typedef Genres::iterator GIter;
typedef Genres::const_iterator GCIter;
 
class App
{
    Genres genres;
    int last_gnum;//���� �ֱٿ� �ο��� �帣 ��ȣ
public:
    App(void);
    ~App(void);
    void Run();
private:
    int SelectMenu();
    void AddGenre(); //�帣 �߰�
    void RemoveGenreByNum();//��ȣ�� �帣 ����
    void RemoveGenreByName();//�̸����� �帣 ����
    void FindGenreByNum()const; //��ȣ�� �帣 �˻�
    void FindGenreByName()const; //�̸����� �帣 �˻�
    void ListGenre()const; //�帣 ��� ����
};
