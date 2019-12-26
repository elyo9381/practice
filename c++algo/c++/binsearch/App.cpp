//App.cpp
#include "App.h"

void App::Run()
{
    int key=NO_DEFINED;
    while((key = SelectMenu())!=ESC)
    {
        switch(key)
        {
        case F1: AddBook(); break;
        case F2: RemoveBook(); break;
        case F3: FindBook(); break;
        case F4: ListAll(); break;        
        default: cout<<"잘못 선택하셨습니다."<<endl; break;
        }
        cout<<"아무 키나 누르세요."<<endl;
        ehglobal::getkey();
    }
}

int App::SelectMenu()
{
    ehglobal::clrscr();//콘솔 화면을 지우기
    cout<<"도서 관리 프로그램 [ESC]: 종료"<<endl;
    cout<<"F1: 도서 추가 F2: 도서 삭제 F3: 도서 검색 F4: 전체 보기"<<endl;

    return ehglobal::getkey();//사용자가 입력한 기능 키 반환
}
void App::AddBook() //도서 추가
{
    cout<<"추가할 도서 번호:";
    int num = ehglobal::getnum();
    if(bstree.FindBook(num))
    {
        cout<<"이미 존재합니다."<<endl;
        return;
    }
    cout<<"도서명:";
    string title = ehglobal::getstr();
    bstree.AddBook(num,title);
}
void App::RemoveBook()//도서 삭제
{
    cout<<"삭제할 도서 번호:";
    int num = ehglobal::getnum();
    
    if(bstree.RemoveBook(num))
    {
        cout<<"삭제하였습니다."<<endl;        
    }
    else
    {
        cout<<"존재하지 않는 도서입니다."<<endl;
    }
 
}
void App::FindBook()const //도서 검색    
{
    cout<<"검색할 도서 번호:";
    int num = ehglobal::getnum();
    
    if(bstree.FindBook(num)==0)    
    {
        cout<<"존재하지 않는 도서입니다."<<endl;
    }
}
void App::ListAll()const //전체 보기
{
    bstree.ListAll();
}
