//App.cpp
#include "App.h"

class EqualerByNum
{
    int num;
public:
    EqualerByNum(int num)
    {
        this->num=num;
    }
    bool operator()(const Genre *genre)const
    {
        return num == genre->GetNum();
    }
};

class EqualerByName
{
    string name;
public:
    EqualerByName(string name)
    {
        this->name = name;
    }
    bool operator()(const Genre *genre)const
    {
        return name.compare(genre->GetName())==0;
    }
};

App::App(void)
{
    last_gnum = 0;
}

App::~App(void)
{
    GIter seek = genres.begin(); //보관한 시작 위치
    GIter last = genres.end(); //보관한 마지막(다음) 위치
    const Genre *genre;
    for(;seek!=last; ++seek)
    {
        genre = (*seek); //간접 연산으로 seek위치에 보관한 장르 확인
        delete genre;
    }
}

void App::Run()
{
    int key=NO_DEFINED;
    while((key = SelectMenu())!=ESC)
    {
        switch(key)
        {
        case F1: AddGenre(); break;
        case F2: RemoveGenreByNum(); break;
        case F3: RemoveGenreByName(); break;
        case F4: FindGenreByNum(); break;
        case F5: FindGenreByName(); break;
        case F6: ListGenre(); break;
        default: cout<<"잘못 선택하셨습니다."<<endl; break;
        }
        cout<<"아무 키나 누르세요."<<endl;
        ehglobal::getkey();
    }
}

int App::SelectMenu()
{
    ehglobal::clrscr();//콘솔 화면을 지우기
    cout<<"장르 관리 프로그램 [ESC]: 종료"<<endl;
    cout<<"F1: 장르 추가 F2: 번호로 장르 삭제 F3: 이름으로 장르 삭제"<<endl;
    cout<<"F4: 번호로 장르 검색 F5: 이름으로 장르 검색 F6: 장르 목록 보기"<<endl;

    return ehglobal::getkey();//사용자가 입력한 기능 키 반환
}
void App::AddGenre() //장르 추가
{
    last_gnum++;
    cout<<last_gnum<<"번째 추가할 장르명:";
    string name = ehglobal::getstr();//장르명 입력
    Genre *genre = new Genre(last_gnum,name); //장르 생성
    genres.push_back(genre);//순차 보관
}



void App::RemoveGenreByNum()//번호로 장르 삭제
{
    int num=0;
    cout<<"삭제할 장르 번호:";
    num = ehglobal::getnum();
    EqualerByNum ebnum(num);

    GIter seek = find_if(genres.begin(), genres.end(), ebnum);
    if(seek != genres.end())
    {
        delete (*seek);
        genres.erase(seek);        
        cout<<"삭제하였습니다."<<endl;
    }
    else
    {
        cout<<"존재하지 않는 장르 번호입니다."<<endl;
    }
}

void App::RemoveGenreByName()//이름으로 장르 삭제
{
    string name;
    cout<<"삭제할 장르명:";
    name = ehglobal::getstr();
    EqualerByName ebname(name);

    GIter seek = find_if(genres.begin(), genres.end(), ebname);
    if(seek != genres.end())
    {
        Genre *genre = (*seek);
        delete genre;
        genres.erase(seek);
        cout<<"삭제하였습니다."<<endl;
    }
    else
    {
        cout<<"존재하지 않는 장르명입니다."<<endl;
    }
}
void App::FindGenreByNum()const //번호로 장르 검색
{
    int num=0;
    cout<<"검색할 장르 번호:";
    num = ehglobal::getnum();
    EqualerByNum ebnum(num);

    GCIter seek = find_if(genres.begin(), genres.end(), ebnum);
    if(seek != genres.end())
    {
        Genre *genre = (*seek);
        genre->View();
    }
    else
    {
        cout<<"존재하지 않는 장르 번호입니다."<<endl;
    }
}
void App::FindGenreByName()const //이름으로 장르 검색
{
    string name;
    cout<<"검색할 장르명:";
    name = ehglobal::getstr();
    EqualerByName ebname(name);

    GCIter seek = find_if(genres.begin(), genres.end(), ebname);
    if(seek != genres.end())
    {
        Genre *genre = (*seek);
        genre->View();
    }
    else
    {
        cout<<"존재하지 않는 장르명입니다."<<endl;
    }
}
void App::ListGenre()const //장르 목록 보기
{
    GCIter seek = genres.begin(); //보관한 시작 위치
    GCIter last = genres.end(); //보관한 마지막(다음) 위치
    const Genre *genre;
    for(   ;seek!=last; ++seek)
    {
        genre = (*seek); //간접 연산으로 seek위치에 보관한 장르 확인
        genre->View(); //장르 정보 출력
    }
}
