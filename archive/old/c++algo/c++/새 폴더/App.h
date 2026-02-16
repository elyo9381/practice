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
    int last_gnum;//가장 최근에 부여한 장르 번호
public:
    App(void);
    ~App(void);
    void Run();
private:
    int SelectMenu();
    void AddGenre(); //장르 추가
    void RemoveGenreByNum();//번호로 장르 삭제
    void RemoveGenreByName();//이름으로 장르 삭제
    void FindGenreByNum()const; //번호로 장르 검색
    void FindGenreByName()const; //이름으로 장르 검색
    void ListGenre()const; //장르 목록 보기
};
